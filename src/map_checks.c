/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:39:22 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/06/26 15:47:18 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	map_is_rectangular(t_map *map)
{
	size_t	columns;
	int		i;

	i = 0;
	columns = ft_strlen(map->map_bytes[i]);
	while (map->map_bytes[i])
	{
		if(ft_strlen(map->map_bytes[i]) != columns)
			return (false);
		i++;
	}
	map->columns = columns;
	return (true);
}

void	only_allowed_chars(t_map *map, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (map->map_bytes[++i])
	{
		j = -1;
		while (map->map_bytes[i][++j])
		{
			if (map->map_bytes[i][j] == 'E')
				map->exits++;
			else if (map->map_bytes[i][j] == 'P')
				map->players++;
			else if (map->map_bytes[i][j] == 'C')
				map->collectables++;
			else if (map->map_bytes[i][j] != '0' && map->map_bytes[i][j] != '1')
				end_game(true, "There's an invalid char in the map", map, game);
		}
	}
	if (map->exits == 1 && map->players == 1 && map->collectables >= 1)
		coord_init(game, map);
	else
		end_game(true, "There's more than one player/ exit/ no collectables", map, game);
	//ft_printf("PLAYER\nline:%d\ncolumn:%d\n", map->p_coord.x, map->p_coord.y);
	//ft_printf("EXIT\nline:%d\ncolumn:%d\n", map->e_coord.x, map->e_coord.y);
}

bool	walls_check(t_map *map)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (map->map_bytes[++i])
	{
		j = -1;
		if (i == 0 || i == map->rows)
		{
			while (map->map_bytes[i][++j])
				if (map->map_bytes[i][j] != '1')
					return (false);
		}
		else
		{
			while (map->map_bytes[i][++j])
				if (map->map_bytes[i][0] != '1' ||
					 map->map_bytes[i][map->columns -1] != '1')
					return (false);
		}
	}
	return (true);
}

bool	valid_path(t_map *map, t_game *game)
{
	char	**map_dup;
	unsigned int		i;

	map_dup = malloc(sizeof (char *) * (map->rows + 1));
	if (!map_dup)
		end_game(true, "Memory allocation faliure at valid_map", map, game);
	i = -1;
	while (map->map_bytes[++i])
		map_dup[i] = ft_strdup(map->map_bytes[i]);
	map_dup[i] = NULL;
	floodfill(map, game, map_dup, map->p_coord);
	map_dup_free(map_dup);
	if (game->path == 1 && game->collected == map->collectables)
		return (true);
	else
		return (false);
}

int	map_checks(t_map *map, t_game *game)
{
	if (!map->map_bytes[0])
		end_game(true, "Map is empty\n", map, game);
	if (!map_is_rectangular(map))
		end_game(true, "Map is not rectangular\n", map, game);
	only_allowed_chars(map, game);
	if (!walls_check(map))
		end_game(true, "There's a gap on the wall\n", map, game);
	if (!valid_path(map, game))
		end_game(true, "There's no valid path on the map\n", map, game);
	map->width = map->columns * SIZE;
	map->height = map->rows * SIZE;
	return (0);
}
