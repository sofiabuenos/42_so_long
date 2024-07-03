/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:45:16 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/07/03 17:24:17 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	path_is_valid(t_game *game, t_map *map)
{
	char				**map_dup;
	unsigned int		i;

	map_dup = malloc(sizeof (char *) * (map->rows + 1));
	if (!map_dup)
		error_msg(game, "Memory allocation faliure at path_is_valid.\n");
	i = -1;
	while (map->map_bytes[++i])
		map_dup[i] = ft_strdup(map->map_bytes[i]);
	map_dup[i] = NULL;
	floodfill(game, map, map_dup, game->current);
	map_dup_free(map_dup);
	if (game->path == 1 && game->collected == map->collect)
		return (true);
	else
		return (false);
}

bool	walls_are_intact(t_map *map)
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

bool	only_allowed_chars(t_game *game, int i, int j)
{
	while (game->map->map_bytes[++i])
	{
		j = -1;
		while (game->map->map_bytes[i][++j])
		{
			if (game->map->map_bytes[i][j] == 'E')
				game->map->exits++;
			else if (game->map->map_bytes[i][j] == 'P')
				game->map->players++;
			else if (game->map->map_bytes[i][j] == 'C')
				game->map->collect++;
			else if (game->map->map_bytes[i][j] != '0'
					&& game->map->map_bytes[i][j] != '1')
				return (false);
		}
	}
	if (game->map->exits == 1 && game->map->players == 1
		&& game->map->collect >= 1)
		coord_init(game);
	else
		error_msg(game, "There's more than one exit/player or no collectable");
	return (true);
}

bool	map_is_rectangular(t_map *map)
{
	size_t	columns;
	int		rows;

	rows = 0;
	columns = ft_strlen(map->map_bytes[rows]);
	while (map->map_bytes[rows])
	{
		if (ft_strlen(map->map_bytes[rows]) != columns)
			return (false);
		rows++;
	}
	map->columns = columns;
	map->rows = rows;
	map->width = map->columns * SIZE;
	map->height = map->rows * SIZE;
	return (true);
}

void	check_errors(t_game *game)
{
	if (!game->map->map_bytes[0])
		error_msg(game, "Map is empty.\n");
	if (!map_is_rectangular(game->map))
		error_msg(game, "Map is not rectangular.\n");
	if (!only_allowed_chars(game, -1, -1))
		error_msg(game, "There's at least one invalid char in the map");
	if (!walls_are_intact(game->map))
		error_msg(game, "There's a gap on the wall.\n");
	if (!path_is_valid(game, game->map))
		error_msg(game, "There's not a valid path on the map.\n");
}
