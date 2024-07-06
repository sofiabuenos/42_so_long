/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:19:17 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/07/06 18:21:58 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	char	*map_name;

	map_name = av[1];
	if (ac != 2)
		ft_printf("Error\nOops! Check parameters, " \
			"please use:./executablle_fle path_to_map_file.ber\n");
	else if (extension_check(map_name))
	{
		ft_putstr_fd("Error\nOops! File extension should be .ber\n", 2);
		exit(1);
	}
	else
		load_game(map_name);
	return (0);
}
