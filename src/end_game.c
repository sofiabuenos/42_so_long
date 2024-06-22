/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:44:52 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/06/17 17:30:35 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	destroy_map(t_map *map)
{
	if (!map)
		return ;
	if (map->map_bytes)
		map_dup_free(map->map_bytes);
	// free(map);
}

void	finish(t_game *game)
{
	if (!game)
		return ;
	// if images
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	#ifdef __linux__
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	#endif
	if (game->mlx)
		free(game->mlx);
}

void	end_game(bool error, char *error_msg, t_map *map, t_game *game)
{
	if (error)
	{
		destroy_map(map);
		finish(game);
		ft_printf("Error\n");
		ft_printf("%s", error_msg);
		exit (1);
	}
}
