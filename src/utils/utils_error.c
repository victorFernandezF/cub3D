/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:49:39 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/13 14:14:20 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	cb_check_players(int p)
{
	if (p < 1)
	{
		ft_putstr_fd("Error\nNeeded one player\n", 2);
		return (false);
	}
	if (p > 1)
	{
		ft_putstr_fd("Error\n Only one player allowed\n", 2);
		return (false);
	}
	return (true);
}

bool	cb_failchar(char c)
{
	ft_putstr_fd("Error\nChar <", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("> not allowed\n", 2);
	return (false);
}

void	cb_fail(char *str)
{
	ft_putstr_fd(str, 2);
	exit (EXIT_FAILURE);
}

void	cb_failrows(char **map, int i, int fd)
{
	cb_freemat_rev(map, i);
	close(fd);
	cb_fail("Error\nFailure allocate rows\n");
}
