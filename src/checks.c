/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:52:44 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/05/06 20:19:39 by sofiabueno       ###   ########.fr       */
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
int	valid_extension(char *map_name)
{
	int	i;

	i = ft_strlen(map_name);
	if (i > 3)
	{
		if (!(ft_strnstr((map_name + (i - 4)), ".ber", 4)))
			return (1);
	}
	return (0);
}
int	count_map_columns(t_map **map)
{
	unsigned int	i;
	unsigned int	line_bytes;
	unsigned int	flag;

	i = 0;
	line_bytes = ft_strlen((*map)->map_blueprint[i]);
	flag = line_bytes;
	while (++i < (*map)->lines)
	{
		line_bytes = ft_strlen((*map)->map_blueprint[i]);
		if (line_bytes != flag)
			return (1);
	}
	(*map)->columns = line_bytes;
	//ft_printf("nbr of columns: %d\n", (*map)->columns);
	return (0);
}
int	count_char(t_map **map, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;
	t_map			*map_temp;

	i = -1;
	count = 0;
	map_temp = *map;
	while (++i < (map_temp)->lines)
	{
		j = 0;
		while (map_temp->map_blueprint[i][j])
		{
			if (map_temp->map_blueprint[i][j] == c)
				count++;
			j++;
		}
	}
	return (count);
}

int	walls_check(t_map **map)
{
	unsigned int lines;
	unsigned int columns;
	unsigned int	i;

	lines = (*map)->lines;
	columns = (*map)->columns;
	i = -1;
	while ((*map)->map_blueprint[1][++i])
		if ((*map)->map_blueprint[1][i] != 1)
			return (1);
	i = -1;
	while ((*map)->map_blueprint[lines -1][++i])
		if ((*map)->map_blueprint[lines -1][i] != 1)
			return (1);
	return(0);
	i = -1;
	while (i < lines)
	{
			if ((*map)->map_blueprint[i][0] != 1 || (*map)->map_blueprint[i][columns -1] != 1)
			return (1);
	}
	return (0);
}

int	check_errors(char *map_name, char *joined_map, t_map **map)
{
	if (valid_extension(map_name))
		return(end_game(1, "Oops! File extension should be .ber"));
	joined_map = read_map(map_name);
	init_map(joined_map, map);
	if (count_map_columns(map))
		return(end_game(1, "Oops! Map must be rectangular"));
	if (count_char(map, 'P') != 1)
		return(end_game(1, "Oops! Duplicated players"));
	if (count_char(map, 'E') != 1)
		return(end_game(1, "Oops! Duplicated exits"));
	if (!count_char(map, 'C'))
		return(end_game(1, "Oops! Map must contain at least one collectible"));
	if (walls_check(map))
		return(end_game(1, "Oops! There is a gap on the wall"));
	return (0);
}
