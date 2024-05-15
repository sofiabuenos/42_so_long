/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:24:57 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/05/14 19:16:57 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/**
 * @brief checks if the given map is in a .ber file.
 * ft_strnstr returns null if it doesnt find .ber to the end of the file name,
 * which implicates error;
 
 * @param map_name 
 * @return 1 - error | 0 - valid extension
 */
int	extension_check(char *map_name)
{
	int		i;

	i = ft_strlen(map_name);
	if (i > 3)
	{
		if (!(ft_strnstr((map_name + (i - 4)), ".ber", 4)))
			return (1);
	}
	return (0);
}

void	coord_init(t_map *map)