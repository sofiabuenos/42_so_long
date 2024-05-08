/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:20:00 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/05/08 20:22:21 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
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
	unsigned int	lines;
	unsigned int	columns;
	unsigned int	players;
	unsigned int	exits;
	unsigned int	collectibles;
	t_point			coord;
}					t_map;


/* FUNCTIONS */
int		check_errors(char *map_name, char *joined_map, t_map **map);
int		valid_extension(char *map_name);
char	*read_map(char *map_name);
int		end_game(int error, char *message);
void	init_map(/*char *map_name, */ char *joined_map, t_map **map);
int		count_char(t_map **map, char c);


#endif