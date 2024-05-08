/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:30:50 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/05/04 21:42:10 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*read_map(char *map_name)
{
	char	*map_next_line;
	char	*joined_map;
	int		fd;
	
	joined_map = ft_strdup("");
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
int	count_map_lines(char *joined_map)
{
	int	lines;

	lines = 0;
	while (*joined_map)
	{
		if (*joined_map == '\n')
		{
			lines++;
		}
		joined_map++;
	}
	if (*joined_map != '\n')
		lines++;
	return (lines);
}

void	init_map(/*char *map_name, */ char *joined_map, t_map **map)
{
	unsigned int i = 0;
	*map = malloc(sizeof(t_map));
	if (!*map)
	{
		ft_printf("Memory allocation failed\n");
		exit(1);
	}
	(*map)->lines = count_map_lines(joined_map);
	(*map)->map_blueprint = ft_split(joined_map, '\n');
	while (i < (*map)->lines)
	{
		printf("%s\n", (*map)->map_blueprint[i]);
		i++;
	}
	free(joined_map);
	//tenho que fazer joined map = null?
}
