/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:20:00 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/05/14 19:09:43 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

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
	t_point			p_current;
	t_point			exit;
}					t_map;


/* FUNCTIONS */
int		extension_check(char *map_name);
void	end_game(bool error, char *error_msg);
void	map_init(char *map_name, char *single_line_map, t_map *map);
int		map_checks(t_map *map);
#endif