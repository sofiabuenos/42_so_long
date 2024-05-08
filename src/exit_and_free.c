/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:26:54 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/05/06 19:33:03 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	end_game(int error, char *message)
{
	if (error)
	{
		ft_printf("Error\n");
		ft_printf("%s", message);
		exit (1);
	}
	return (0);
}