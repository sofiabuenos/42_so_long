/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:31:00 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/06/27 19:13:14 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	read_and_get_map(t_game *game, char *map_name)
{
	int		fd;
	char	*line;
	char	*lined_map;

	lined_map = NULL;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		error_msg(game, "Couldn't open map file :(\n");
	line = get_next_line(fd);
	while (line)
	{
		lined_map = ft_strjoin_gnl(lined_map, line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	if (lined_map)
	{
		game->map->map_bytes = ft_split(lined_map, '\n');
		free(lined_map);
	}
}

void	init_map(t_game *game, char *map_name)
{
	t_map	*map;
	int i;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		error_msg(game, "Error initiating map structure.\n");
	game->map = map;
	read_and_get_map(game, map_name);
	if(game->map->map_bytes)
	{
		i = -1;
		while (game->map->map_bytes[++i])
			ft_printf("%s\n", game->map->map_bytes[i]);
		
	}
	else // (if (!game->map->map_bytes))
		error_msg(game, "Error allocating map or map file is empty.\n");
}

void	load_game(char *map_name)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	init_map(&game, map_name);
	check_errors(&game);
}