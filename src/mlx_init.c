/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:59:40 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/05/22 20:39:13 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


// int	make_window()
// {
// 	void *mlx;
// 	void *mlx_win;

// 	mlx = mlx_init();
// 	if (!mlx)
// 		end_game(true, "Memory Allocation error at mlx_init");
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "So_long");
// 	mlx_put_image_to_window()
// 	mlx_hook(mlx_win, 17, 0L, read_key, NULL);
// 	mlx_loop(mlx);
// 	return (0);
// }

//  SINGLETON CONCEPT TO STUDY <3

typedef struct s_jeitinho
{
	t_map *map;
	t_game *game;
} t_jeitinho;


t_jeitinho *mapc(void)
{
	static t_jeitinho map;
	
	return (&map);
}

int read_key( int key, void *data)
{
	(void)data;
	
	printf("voce clicou: %c\n", key);
	end_game(true, "game ", mapc()->map, mapc()->game);
	return (0);
}

int	play_game(t_map *map, t_game *game)
{
	mapc()->map = map;
	mapc()->game = game;


	printf(" veio do jeitinho : %d\n", mapc()->map->columns);
	game->mlx = mlx_init();
	if (!game->mlx)
		end_game(true, "Couldn't initialize MLX", map, game);
	game->window = mlx_new_window(game->mlx, map->width, map->height, "So_long");
	if (!game->window)
		end_game(true, "Couldn't create a new window", map, game);
	mlx_hook(game->window, 17, 0L, read_key, NULL);
	mlx_loop(game->mlx);
	return (0);
}