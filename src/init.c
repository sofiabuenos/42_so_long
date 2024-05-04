/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:30:50 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/05/03 17:42:50 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*read_map(/*t_map *map,*/ char *map_name)
{
	int		fd;
	char	*map_next_line;
 	char	*joined_map;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("The file is not opening :/");
		exit(1);
	}
	map_next_line = get_next_line(fd);
	while (map_next_line)
	{
		joined_map = ft_strjoin(joined_map, map_next_line);
		free(map_next_line);
		map_next_line = get_next_line(fd);
	}
	free(map_next_line);
	close(fd);
	return (joined_map);
}
