/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:19:17 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/06/27 15:18:38 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	char	*map_name;

	map_name = av[1];
	if (ac != 2)
		ft_printf("Oops! Check parameters, please use:./executablle_fle path_to_map_file.ber\n");
	else if (extension_check(map_name))
	{
		ft_printf("Oops! File extension should be .ber\n");
		exit(1);
	}
	load_game(map_name);
	//map_init(map_name, single_line_map, &map, &game); 
	//map_checks(&map, &game);
	//map_dup_free(map.map_bytes);
	//play_game(&map, &game);
	return (0);
}
