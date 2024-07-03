/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:44:52 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/07/03 19:52:00 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	finish_game(void *data)
{
	t_game	*game;

	game = (t_game *)data;
	if (game->map->collect == 0)
	{
		kill_game(game);
		ft_printf("Congrats!\n");
	}
	else
	{
		kill_game(game);
		ft_printf("You quit!\n");
	}
	exit(0);
}

void	kill_images(t_game *game)
{
	int	i;

	i = -1;
	while (++i < IMG_NUM)
		mlx_destroy_image(game->mlx, game->images[i].img);
	free(game->images);
}

void	kill_map(t_map *map)
{
	if (!map)
		return ;
	if (map->map_bytes)
		map_dup_free(map->map_bytes);
	free(map);
}

/**
 * @brief 
 * para mac usar:
 * 	#ifdef __linux__
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	#endif
 * @param game 
 */
void	kill_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		kill_map(game->map);
	if (game->images)
		kill_images(game);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	error_msg(t_game *game, char *msg)
{
	if (game)
		kill_game(game);
		ft_printf("Error\n");
	ft_printf(msg);
	exit(1);
}
