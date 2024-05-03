/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:20:00 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/04/29 21:41:31 by sofiabueno       ###   ########.fr       */
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
	char			**map;
	unsigned int	lines;
	unsigned int	columns;
	unsigned int	players;
	unsigned int	exits;
	unsigned int	collectibles;
}					t_map;

/* FUNCTIONS */
int	valid_extension(char *map_name);

#endif