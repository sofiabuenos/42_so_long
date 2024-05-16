/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:39:22 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/05/15 16:59:27 by sbueno-s         ###   ########.fr       */
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

void	only_allowed_chars(t_map *map)
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
			else if (map->map_bytes[i][j] != '0' && map->map_bytes[i][j] != '1')
				end_game(true, "There's an invalid char in the map");
		}
	}
	if (map->exits == 1 && map->players == 1 && map->collectibles >= 1)
		coord_init(map);
	else
		end_game(true, "There's more than one player/ exit/ no collectibles");
	//ft_printf("PLAYER\nline:%d\ncolumn:%d\n", map->p_coord.x, map->p_coord.y);
	//ft_printf("EXIT\nline:%d\ncolumn:%d\n", map->e_coord.x, map->e_coord.y);
}

bool	walls_check(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map_bytes[++i])
	{
		j = -1;
		while (map->map_bytes[i][++j])
		{
			
		}
	}
}

int	map_checks(t_map *map)
{
	
	if (!map->map_bytes[0])
		end_game(true, "Map is empty\n");
	if (!map_is_rectangular(map))
		end_game(true, "Map is not rectangular\n");
	only_allowed_chars(map);
	return (0);
}
