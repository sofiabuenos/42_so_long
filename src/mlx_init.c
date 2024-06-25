/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:59:40 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/06/25 16:38:41 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


//  SINGLETON CONCEPT TO STUDY <3

typedef struct s_staddress
{
	t_map *map;
	t_game *game;
} t_staddress;


t_staddress *map_add(void)
{
	static t_staddress map;
	return (&map);
}

int finish_game( int event, void *data)
{
	(void)data;
	
	printf("voce clicou: %c\n", event);
	end_game(true, "game over", map_add()->map, map_add()->game);
	return (0);
}
/**
 * @brief reads a XPM file, and alocates memory for it.
 * mlx_xpm_file_to_image, gets the location of the xpm file and returns
 * the result in game->images[index], an array of t_images
 * @param map 
 * @param game 
 */
void	load_images(t_map *map, t_game *game)
{
	game->images = malloc(IMG_NUM * sizeof(t_images));
	if (!game->images)
		end_game(true, "Images memory allocation issue.\n", map, game);
	game->images[B].img = mlx_xpm_file_to_image(game->mlx, IB, &game->images[B].width, &game->images[B].width);
	game->images[O].img = mlx_xpm_file_to_image(game->mlx, IO, &game->images[O].width, &game->images[O].width);
	game->images[P].img = mlx_xpm_file_to_image(game->mlx, IP, &game->images[P].width, &game->images[P].width);
	game->images[C].img = mlx_xpm_file_to_image(game->mlx, IC, &game->images[C].width, &game->images[C].width);
}

void	place_images(t_map *map, t_game *game, t_point coord)
{
	t_images sprite;
	if (map->map_bytes[coord.y][coord.x] == WALL)
		sprite = game->images[O];
	else if (map->map_bytes[coord.y][coord.x] == PLAYER)
		sprite = game->images[P];
	else if (map->map_bytes[coord.y][coord.x] == COLLECT)
		sprite = game->images[C];
	else if (map->map_bytes[coord.y][coord.x] != WALL)
		sprite = game->images[B];
	// if (!game->mlx || !game->window || !sprite.img) {
    //     printf("Invalid argument to mlx_put_image_to_window\n");
    //     return;
    // }
	mlx_put_image_to_window(game->mlx, game->window, sprite.img, (SIZE * coord.x), (SIZE * coord.y));
}

void	display_images(t_map *map, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (map->map_bytes[++i])
	{
		j = -1;
		while (map->map_bytes[i][++j])
			place_images(map, game, (t_point){j, i});
	}
}
/**
 * @brief this function saves where the player needs to go according to
 * the key pressed by the user. this function needs to return an int because
 * minilibx expects callback functions to return an int.
 * @param keycode 
 * @param game 
 * @return int 
 */
int	pressed_key(int keycode, t_game *game)
{
	if (keycode == ESC || keycode == Q)
		//funcao para terminar o jogo com um ganhou/ perdeu; pode ser a finish_game mais elaborada
	if (keycode == UP || keycode == W)
		game->next = (t_point){game->current.x, game->current.y - 1};
	if (keycode == DOWN || keycode == S)
		game->next = (t_point){game->current.x, game->current.y + 1};
	else if (keycode == LEFT || keycode == A)
		game->next = (t_point){game->current.x - 1, game->current.y};
	else if (keycode == RIGHT || keycode == D)
		game->next = (t_point){game->current.x + 1, game->current.y};
	return (keycode);
}

int	put_game(t_game *game, t_map *map)
{
	printf("%d, %d \n", game->next.y, game->next.x);
	if (!player_moved(game, map, game->next))
		return (0);
	printf("entro na funcao player_moved\n");
	game->moves++;
	ft_printf("Number of moves: %d\n", game->moves);
	move_player(game, map);
	return (0);
}
/**
 * @brief 
 * mlx_init - creates the connection between the software and the display (screen)
 * mlx_new_window - creates a window using the sizes and the title as parameters
 * @param map 
 * @param game 
 * @return int 
 */
int	play_game(t_map *map, t_game *game)
{
	map_add()->map = map;
	map_add()->game = game;

	game->mlx = mlx_init();
	if (!game->mlx)
		end_game(true, "Couldn't initialize MLX", map, game);
	game->window = mlx_new_window(game->mlx, map->width, map->height, "So_long");
	if (!game->window)
		end_game(true, "Couldn't create a new window", map, game);
	load_images(map, game);
	display_images(map, game);
	mlx_hook(game->window, 2, KEY_MASK, pressed_key, game);
	mlx_hook(game->window, 17, 0L, finish_game, NULL);
	printf("%d, %d \n", game->next.y, game->next.x);
	mlx_loop_hook(game->mlx, put_game, NULL);
	mlx_loop(game->mlx);
	return (0);
}
