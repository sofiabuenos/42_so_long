/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:44:52 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/06/27 16:30:45 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	#ifdef __linux__
 	if (game->mlx)
 		mlx_destroy_display(game->mlx);
 	#endif
	free(game->mlx);
}

void	error_msg(t_game *game, char *msg)
{
	if (game)
		kill_game(game);
	if (game->window) // necessário?
		mlx_destroy_window(game->mlx, game->window); 
	#ifdef __linux__ // necessário? 
 	if (game->mlx)
 		mlx_destroy_display(game->mlx);
 	#endif
	free(game->mlx);
	ft_printf(msg);
	exit(1);
}



// void	end_game(bool error, char *error_msg, t_map *map, t_game *game)
// {
// 	if (error)
// 	{
// 		destroy_map(map);
// 		finish(game);
// 		ft_printf("Error\n");
// 		ft_printf("%s", error_msg);
// 		exit (1);
// 	}
// }
