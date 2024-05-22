/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:19:17 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/05/22 19:54:59 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	char	*map_name;
	char	*single_line_map;
	t_map	map;
	t_game	game;

	map_name = av[1];
	single_line_map = NULL;
	if (ac != 2)
		end_game(true, "Oops! missing parameters, please use:./executablle_fle path_to_map_file.ber\n", &map, &game);
	if(extension_check(map_name))
		end_game(true, "Oops! File extension should be .ber", &map, &game);
	map_init(map_name, single_line_map, &map, &game);
	map_checks(&map, &game);
	//map_dup_free(map.map_bytes);
	play_game(&map, &game);
	return (0);
}
