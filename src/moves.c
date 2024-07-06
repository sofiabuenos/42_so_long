/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:22:37 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/07/06 18:36:23 by sbueno-s         ###   ########.fr       */
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

void	action(t_game *game)
{
	place_images(game, game->next);
	place_images(game, game->current);
	place_images (game, game->finish);
	game->current = game->next;
}

t_map_chars	element(t_game *game, t_point pos)
{
	return (game->map->map_bytes[pos.y][pos.x]);
}

void	collect_check(t_game *game)
{
	game->map->collect--;
	game->map->map_bytes[game->next.y][game->next.x] = PLAYER;
	if (game->map->map_bytes[game->current.y][game->current.x] == LOCKP)
		game->map->map_bytes[game->current.y][game->current.x] = EXIT;
	else
		game->map->map_bytes[game->current.y][game->current.x] = FLOOR;
	if (game->map->collect == 0)
		game->map->map_bytes[game->finish.y][game->finish.x] = WOUT;
}

void	move_player(t_game *game)
{
	if (element(game, game->next) == COLLECT)
	{
		collect_check(game);
	}
	else if (game->map->collect != 0 && (element(game, game->next) == EXIT))
	{
		game->map->map_bytes[game->next.y][game->next.x] = LOCKP;
		game->map->map_bytes[game->current.y][game->current.x] = FLOOR;
	}
	else if (element(game, game->next) == WOUT)
		game->map->map_bytes[game->next.y][game->next.x] = FIN;
	else
	{
		game->map->map_bytes[game->next.y][game->next.x] = PLAYER;
		if (game->map->map_bytes[game->current.y][game->current.x] == LOCKP)
			game->map->map_bytes[game->current.y][game->current.x] = EXIT;
		else
			game->map->map_bytes[game->current.y][game->current.x] = FLOOR;
	}
	action(game);
}
