/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:22:37 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/07/01 20:23:52 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	player_moved(t_game *game, t_point next)
{
	if (game->map->map_bytes[next.y][next.x] == WALL)
		return (0);
	else if (next.y == game->current.y && next.x == game->current.x)
		return (0);
	return (1);
}

t_map_chars	element(t_game *game, t_point pos)
{
	return (game->map->map_bytes[pos.y][pos.x]);
}

void	move_player(t_game *game)
{
	if (element(game, game->next) == COLLECT)
		game->map->collect--;
	if (game->map->collect == 0)
		game->map->map_bytes[game->finish.y][game->finish.x] = WOUT;
	if (element(game, game->next) == WOUT)
		game->map->map_bytes[game->next.y][game->next.x] = FIN;
	else
		game->map->map_bytes[game->next.y][game->next.x] = PLAYER;
	game->map->map_bytes[game->current.y][game->current.x] = FLOOR;
	place_images(game, game->next);
	place_images(game, game->current);
	place_images (game, game->finish);
	game->current = game->next;
}
