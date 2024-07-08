/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:31:00 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/07/08 15:44:46 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	no_empty_line(t_game *game, char *map_str)
{
	int	i;

	if (map_str[0] == '\n' || map_str[0] == '\0' || map_str[ft_strlen(map_str) - 1] == '\n')
		{
			free(map_str);
			error_msg (game, "There's an emty line on the map\n");
		}
	i = -1;
	while (map_str[++i])
	{
		if (map_str[i] == '\n' && map_str[i + 1] == '\n')
		{
			free(map_str);
			error_msg (game, "There's an emty line on the map\n");
		}
	}
	return (1);
}

void	read_and_get_map(t_game *game, char *map_name)
{
	int		fd;
	char	*line;
	char	*map_str;

	map_str = NULL;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		error_msg(game, "Couldn't open map file :(\n");
	line = get_next_line(fd);
	while (line)
	{
		map_str = ft_strjoin_gnl(map_str, line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	if (no_empty_line(game, map_str))
	{
		game->map->map_bytes = ft_split(map_str, '\n');
		free(map_str);
	}
}

void	init_map(t_game *game, char *map_name)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		error_msg(game, "Error initiating map structure.\n");
	game->map = map;
	read_and_get_map(game, map_name);
	if (!game->map->map_bytes)
		error_msg(game, "Error allocating map or map file is empty.\n");
}

void	load_game(char *map_name)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	init_map(&game, map_name);
	check_errors(&game);
	set_graphics(&game);
}
