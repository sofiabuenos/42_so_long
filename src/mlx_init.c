/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:59:40 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/05/20 17:10:46 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

#define WIDTH 400
#define HEIGHT 400

int read_key( int key, void *data)
{
	(void)data;
	end_game(true, "game over");
	printf("voce clicou: %c\n", key);
	return (0);
}

int	make_window()
{
	void *mlx;
	void *mlx_win;

	mlx = mlx_init();
	if (!mlx)
		end_game(true, "Memory Allocation error at mlx_init");
	mlx_win = mlx_new_window(mlx, 1920, 1080, "So_long");
	mlx_put_image_to_window()
	mlx_hook(mlx_win, 17, 0L, read_key, NULL);
	mlx_loop(mlx);
	return (0);
}