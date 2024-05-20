/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:23:28 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/05/17 16:37:43 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*read_map(char *map_name, char *single_line_map)
{
	int		fd;
	char	*map_line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		end_game(true, "Couldn't open map file :/");
	map_line = get_next_line(fd);
	while (map_line)
	{
		single_line_map = ft_strjoin_gnl(single_line_map, map_line);
		free(map_line);
		map_line = get_next_line(fd);
	}
	free(map_line);
	close(fd);
	return (single_line_map);
}
void	count_map_lines(char *single_line_map, t_map *map)
{
	int	rows;

	rows = 0;
	while (*single_line_map)
	{
		if (*single_line_map == '\n')
			rows++;
		single_line_map++;
	}
	if (*single_line_map != '\n') // ver se fazer && *single_line_map resolve o problema de ler o null
		rows++;
	map->rows = rows;
	printf("count_map_lines - %d", map->rows);
}

void	map_init(char *map_name, char *single_line_map, t_map *map, t_game *game)
{
	unsigned int	i;

	ft_bzero(map, sizeof(t_map));
	ft_bzero(game, sizeof(t_game));
	single_line_map = read_map(map_name, single_line_map);
	count_map_lines(single_line_map, map);
	map->map_bytes = ft_split(single_line_map, '\n');
	i = -1;
	while (map->map_bytes[++i])
		ft_printf("%s\n", map->map_bytes[i]);
	free(single_line_map);
}
