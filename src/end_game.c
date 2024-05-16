/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:44:52 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/05/15 15:26:56 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	end_game(bool error, char *error_msg)
{
	if (error)
	{
		ft_printf("Error\n");
		ft_printf("%s", error_msg);
		exit (1);
	}
}
