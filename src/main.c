/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:19:17 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/04/29 14:38:33 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	char *map;

	map = av[1];
	if (ac != 2)
		ft_printf("Check prompt - use: %s path_and_map_name.ber", av[0]);
	else
		if ((valid_extension(map)))
		{
			ft_printf("File extension should be .ber");
			exit (1);
		}
		else
		ft_printf("proceed other checks");
	return (0);
}
