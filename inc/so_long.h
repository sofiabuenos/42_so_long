/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:20:00 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/05/20 16:49:44 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include "../minilibx-linux/mlx.h"
#include "../minilibx-mac/mlx.h"

/* STRUCTS */
typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
}					t_point;

typedef struct s_map
{
	char			**map_bytes;
	unsigned int	rows;
	unsigned int	columns;
	unsigned int	players;
	unsigned int	exits;
	unsigned int	collectibles;
	t_point			p_coord;
	t_point			e_coord;
}					t_map;

typedef struct s_game
{
	unsigned int	collected;
	bool			path;
}					t_game;

/* FUNCTIONS */
int		extension_check(char *map_name);
void	end_game(bool error, char *error_msg);
void	map_init(char *map_name, char *single_line_map, t_map *map, t_game *game);
int		map_checks(t_map *map, t_game *game);
void	coord_init(t_map *map);
void	floodfill(t_map *map, t_game *game, char **map_dup, t_point pos);
void	map_dup_free(char **map_dup);
int		make_window();
#endif