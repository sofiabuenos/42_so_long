/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:24:57 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/06/26 16:38:45 by sbueno-s         ###   ########.fr       */
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

void	init_game_current_pos(t_game *game, int x, int y)
{
	game->current.x = x;
	game->current.y = y;
}
/**
 * @brief this function saves the player and exit's statring positions.
 * x - rows
 * y - columns
 * @param map 
 */
void	coord_init(t_game *game, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map_bytes[++i])
	{
		j = -1;
		while (map->map_bytes[i][++j])
		{
			if (map->map_bytes[i][j] == 'P')
			{
				map->p_coord.x = i;
				map->p_coord.y = j;
				init_game_current_pos(game, i, j);
				// //game->next = game->current;
				printf("%d, %d\n", game->current.y, game->current.x);
			}
			else if (map->map_bytes[i][j] == 'E')
			{
				map->e_coord.x = i;
				map->e_coord.y = j;
			}
		}
	}
	
}

void	floodfill(t_map *map, t_game *game, char **map_dup, t_point pos)
{
	if (pos.x < 0 || pos.y < 0 || pos.x >= map->rows || pos.y >= map->columns)
		return ;
	if (map_dup[pos.x][pos.y] == '1')
		return ;
	else if (map_dup[pos.x][pos.y] == 'C')
		game->collected++;
	else if (map_dup[pos.x][pos.y] == 'E')
		game->path = true;
	map_dup[pos.x][pos.y] = '1';
	floodfill(map, game, map_dup, (t_point){pos.x - 1, pos.y}); // esquerda
	floodfill(map, game, map_dup, (t_point){pos.x + 1, pos.y}); // direira
	floodfill(map, game, map_dup, (t_point){pos.x, pos.y - 1}); // cima
	floodfill(map, game, map_dup, (t_point){pos.x, pos.y + 1}); // baixo
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
