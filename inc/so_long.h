/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:20:00 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/05/06 15:53:01 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

/* STRUCTS */

typedef struct s_map
{
	char			**map_blueprint;
	unsigned int	lines;
	unsigned int	columns;
	unsigned int	players;
	unsigned int	exits;
	unsigned int	collectibles;
}					t_map;

/* FUNCTIONS */
int		check_errors(char *map_name, char *joined_map, t_map **map);
int		valid_extension(char *map_name);
char	*read_map(char *map_name);
int		end_game(int error, char *message);
void	init_map(/*char *map_name, */ char *joined_map, t_map **map);
int		count_char(t_map **map, char c);


#endif