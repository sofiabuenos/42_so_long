/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:19:17 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/07/03 16:29:37 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	char	*map_name;

	map_name = av[1];
	if (ac != 2)
		ft_printf("Oops! Check parameters, \
			please use:./executablle_fle path_to_map_file.ber\n");
	else if (extension_check(map_name))
	{
		ft_putstr_fd("Oops! File extension should be .ber\n", 2);
		exit(1);
	}
	else
		load_game(map_name);
	return (0);
}
