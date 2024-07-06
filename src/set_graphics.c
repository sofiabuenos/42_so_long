/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:22:25 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/07/06 17:09:34 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	put_game(void *data)
{
	t_game	*game;

	game = (t_game *)data;
	if (!player_moved(game, game->next))
		return (0);
	game->moves++;
	ft_printf(CYAN"Number of moves: %d\n"RESET, game->moves);
	move_player(game);
	if (game->map->map_bytes[game->finish.y][game->finish.x] == FIN)
		finish_game(game);
	return (0);
}

int	pressed_key(int keycode, void *data)
{
	t_game	*game;

	game = (t_game *)data;
	if (keycode == ESC || keycode == Q)
		finish_game(game);
	else if (keycode == UP || keycode == W)
		game->next = (t_point){game->current.x, (game->current.y - 1)};
	else if (keycode == DOWN || keycode == S)
		game->next = (t_point){game->current.x, (game->current.y + 1)};
	else if (keycode == LEFT || keycode == A)
		game->next = (t_point){(game->current.x - 1), game->current.y};
	else if (keycode == RIGHT || keycode == D)
		game->next = (t_point){(game->current.x + 1), game->current.y};
	return (0);
}

void	display_images(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map->map_bytes[++i])
	{
		j = -1;
		while (game->map->map_bytes[i][++j])
			place_images(game, (t_point){j, i});
	}
}

void	load_images(t_game *game)
{
	game->images = malloc(IMG_NUM * sizeof(t_images));
	if (!game->images)
		error_msg(game, "Images memory allocation issue.\n");
	game->images[BACK].img = mlx_xpm_file_to_image(game->mlx, IBACK,
			&game->images[BACK].width, &game->images[BACK].height);
	game->images[OBST].img = mlx_xpm_file_to_image(game->mlx, IOBST,
			&game->images[OBST].width, &game->images[OBST].height);
	game->images[PLAY].img = mlx_xpm_file_to_image(game->mlx, IPLAY,
			&game->images[PLAY].width, &game->images[PLAY].height);
	game->images[COLL].img = mlx_xpm_file_to_image(game->mlx, ICOLL,
			&game->images[COLL].width, &game->images[COLL].height);
	game->images[EXI].img = mlx_xpm_file_to_image(game->mlx, IEXI,
			&game->images[EXI].width, &game->images[EXI].height);
	game->images[OPDOOR].img = mlx_xpm_file_to_image(game->mlx,
			IOPDOOR, &game->images[OPDOOR].width, &game->images[OPDOOR].height);
	game->images[LOCKPL].img = mlx_xpm_file_to_image(game->mlx,
			ILPLAY, &game->images[LOCKPL].width, &game->images[LOCKPL].height);
	game->images[FINISH].img = mlx_xpm_file_to_image(game->mlx, IFINISH,
			&game->images[FINISH].width, &game->images[FINISH].height);
}

void	set_graphics(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_msg(game, "Error initiating MLX.\n");
	game->window = mlx_new_window(game->mlx, game->map->width,
			game->map->height, "So_long");
	if (!game->window)
		error_msg(game, "Error creating new window.\n");
	load_images(game);
	display_images(game);
	mlx_hook(game->window, 2, KEY_MASK, pressed_key, game);
	mlx_hook(game->window, 17, 0L, finish_game, game);
	mlx_loop_hook(game->mlx, put_game, game);
	mlx_loop(game->mlx);
}
