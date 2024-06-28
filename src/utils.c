/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:24:57 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/06/28 16:44:29 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * @brief checks if the given map is in a .ber file.
 * ft_strnstr returns null if it doesnt find .ber to the end of the file name,
 * which implicates error;
 
 * @param map_name 
 * @return 1 - error | 0 - valid extension
 */
int	extension_check(char *map_name)
{
	int		i;

	i = ft_strlen(map_name);
	if (i > 3)
	{
		if (!(ft_strnstr((map_name + (i - 4)), ".ber", 4)))
			return (1);
	}
	return (0);
}

/**
 * @brief this function saves the player and exit's statring positions.
 * y - rows
 * x - columns
 * check: printf("current y: %d\n, current x: %d\n", game->current.y, game->current.x);
 * @param map 
 */

void	coord_init(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map->map_bytes[++i])
	{
		j = -1;
		while (game->map->map_bytes[i][++j])
		{
			if (game->map->map_bytes[i][j] == 'P')
				game->current = (t_point){j, i};
			else if (game->map->map_bytes[i][j] == 'E')
				game->finish = (t_point){j, i};
		}
	}
 }

void	floodfill( t_game *game, t_map *map, char **map_dup, t_point pos)
{
	if (pos.x < 0 || pos.y < 0 || pos.x >= map->columns || pos.y >= map->rows)
		return ;
	if (map_dup[pos.y][pos.x] == '1')
		return ;
	else if (map_dup[pos.y][pos.x] == 'C')
		game->collected++;
	else if (map_dup[pos.y][pos.x] == 'E')
		game->path = true;
	map_dup[pos.y][pos.x] = '1';
	floodfill(game, map, map_dup, (t_point){pos.x - 1, pos.y});
	floodfill(game, map, map_dup, (t_point){pos.x + 1, pos.y});
	floodfill(game, map, map_dup, (t_point){pos.x, pos.y - 1});
	floodfill(game, map, map_dup, (t_point){pos.x, pos.y + 1});
}

void	map_dup_free(char **map_dup)
{
	int	i;

	i = -1;
	while (map_dup[++i])
		free(map_dup[i]);
	free(map_dup[i]);
	free(map_dup);
}

void	place_images(t_game *game, t_point coord)
{
	t_images sprite;
	if (game->map->map_bytes[coord.y][coord.x] == WALL)
		sprite = game->images[OBST];
	else if (game->map->map_bytes[coord.y][coord.x] == PLAYER)
		sprite = game->images[PLAY];
	else if (game->map->map_bytes[coord.y][coord.x] == COLLECT)
		sprite = game->images[COLL];
	else if (game->map->map_bytes[coord.y][coord.x] != WALL)
		sprite = game->images[BACK];
	// if (!game->mlx || !game->window || !sprite.img) {
    //     printf("Invalid argument to mlx_put_image_to_window\n");
    //     return;
    // }
	mlx_put_image_to_window(game->mlx, game->window, sprite.img, (SIZE * coord.x), (SIZE * coord.y));
}
