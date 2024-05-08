/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:19:17 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/05/06 19:04:37 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	char	*map_name;
	char	*joined_map;
	t_map	*map = NULL;

	map_name = av[1];
	joined_map = NULL;
	if (ac != 2)
	{
		ft_printf("Check prompt - use: %s path_and_map_name.ber", av[0]);
		exit (1);
	}
	else
	{
		check_errors(map_name, joined_map, &map);
	}
	
	return (0);
}
