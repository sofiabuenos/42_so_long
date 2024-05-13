/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:19:17 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/05/10 16:40:07 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	char	*map_name;

	map_name = av[1];
	if (ac != 2)
		ft_printf("Please use: %s path_to_map_file.ber\n", av[0]);
	if(extension_check(map_name))
		end_game(true, "Oops! File extension should be .ber");
	map_checks();
}
