/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:30:50 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/05/08 20:22:21 by sbueno-s         ###   ########.fr       */
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

char	**remove_empty_lines(char **map_bytes, unsigned int *lines)
{
	char	**new_map;
	unsigned int i;
	unsigned int j;

	new_map = malloc(sizeof(char *) * (*lines + 1));
	if (!new_map)
	{
		ft_printf("Memory allocation failed\n");
		exit(1);
	}
	i = 0;
	j = 0;
	while (i < *lines)
	{
		if (ft_strlen(map_bytes[i]) > 0)
		{
			new_map[j] = ft_strdup(map_bytes[i]);
			j++;
		}
		i++;
	}
	new_map[j] = NULL;
	*lines = j; // update the number of lines
	return (new_map);
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
	(*map)->map_bytes = ft_split(joined_map, '\n');
	(*map)->map_bytes = remove_empty_lines((*map)->map_bytes, &(*map)->lines);
	while (i < (*map)->lines)
	{
		printf("%s\n", (*map)->map_bytes[i]);
		i++;
	}
	free(joined_map);
	//tenho que fazer joined map = null?
}
