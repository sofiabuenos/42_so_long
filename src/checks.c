/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:52:44 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/05/08 20:38:14 by sbueno-s         ###   ########.fr       */
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

	if ((*map)->lines == 0)
		return (1);
	i = 0;
	line_bytes = ft_strlen((*map)->map_bytes[i]);
	flag = line_bytes;
	while (++i < (*map)->lines)
	{
		line_bytes = ft_strlen((*map)->map_bytes[i]);
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
		while (map_temp->map_bytes[i][j])
		{
			if (map_temp->map_bytes[i][j] == c)
				count++;
			if (map_temp->map_bytes[i][j] == 'P')
			{
				(*map)->coord.x = i;
				(*map)->coord.y = j;
			}
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
	while ((*map)->map_bytes[0][++i])
		if ((*map)->map_bytes[0][i] != '1')
			return (1);
	i = -1;
	while ((*map)->map_bytes[lines -1][++i])
		if ((*map)->map_bytes[lines -1][i] != '1')
			return (1);
	i = -1;
	while (++i < lines)
	{
			if ((*map)->map_bytes[i][0] != '1' || (*map)->map_bytes[i][columns -1] != '1')
			{
				ft_printf("char %d: %c\n", i, (*map)->map_bytes[i][0]);
				ft_printf("char %d: %c\n", i, (*map)->map_bytes[i][0]);
				return (1);
			}
	}
	return (0);
}

int	valid_chars(t_map **map)
{
	unsigned int	i;
	unsigned int	j;
	char			*allowed_chars;

	i = -1;
	allowed_chars = "01EPC";
	while ((*map)->map_bytes[++i])
	{
		j = -1;
		while((*map)->map_bytes[i][++j])
			if(!ft_strchr(allowed_chars, (*map)->map_bytes[i][j]))
				return (1);
	}
	return (0);
}
void	flood_fill(t_map **map, t_point *coord)
{
	unsigned int	coins;

	coins = 0;
	if (coord.x > (*map)->lines -1 || coord.y > (*map)->columns -1 || 
			(*map)->map_bytes[coord.x][coord.y] == 'A')
		return ;
	if ((*map)->map_bytes[coord.x][coord.y] == 'C')
		coins++;
	if ((*map)->map_bytes[coord.x][coord.y] != '0')
		(*map)->map_bytes[coord.x][coord.y] == 'A';
	flood_fill(map, (t_point){coord.x - 1}{coord.y});
	flood_fill(map, (t_point){coord.x + 1}{coord.y});
	flood_fill(map, (t_point){coord.x}{coord.y - 1});
	flood_fill(map, (t_point){coord.x}{coord.y + 1});
	
}


int	check_errors(char *map_name, char *joined_map, t_map **map)
{
	if (valid_extension(map_name))
		return(end_game(1, "Oops! File extension should be .ber"));
	joined_map = read_map(map_name);
	init_map(joined_map, map);
	if (valid_chars(map))
		return(end_game(1, "Oops! There's an invalid char"));
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
