/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:51:15 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/06/25 16:29:50 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	player_moved(t_game *game, t_map *map, t_point next)
{
	printf("entro na funcao player_moved\n");
	if (map->map_bytes[next.y][next.x] == WALL)
		return (0);
	else if (next.y == game->current.x && next.x == game->current.y)
		return (0);
	return (1);
}
t_map_chars element(t_map *map, t_point pos)
{
	return(map->map_bytes[pos.y][pos.x]);
}

void	move_player(t_game *game, t_map *map)
{
	if (element(map, game->next) == COLLECT)
		map->collectables--;
	map->map_bytes[game->next.y][game->next.x] = PLAYER;
	map->map_bytes[game->current.y][game->current.x] = FLOOR;
	place_images(map, game, game->next);
	place_images(map, game, game->next);
	game->current = game->next;
}

