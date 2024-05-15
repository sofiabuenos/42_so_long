/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:39:22 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/05/14 19:15:43 by sofiabueno       ###   ########.fr       */
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

bool	only_allowed_chars(t_map *map)
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
				map->collectibles++;
			else if (map->map_bytes[i][j] != '0' || map->map_bytes[i][j] != '1')
				end_game(true, "There's an invalid char in the map");
		}
	}
	if (map->exits = 1 || map->players = 1 || map->collectibles >= 1)
	// Terminar - criar uma funcao para indicar onde está a posicao atual do player e da exit
	// criar duas t_points na estrutura principal para guardar essas posicoes.
}

int	map_checks(t_map *map)
{
	
	if (!map->map_bytes[0])
		end_game(true, "Map is empty\n");
	if (!map_is_rectangular(map))
		end_game(true, "Map is not rectangular\n");
	return (0);
}