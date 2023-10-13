/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:49:39 by fortega-          #+#    #+#             */
/*   Updated: 2023/10/13 12:29:32 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cb_examplefile(void)
{
	printf("\n*****\nExample map file:\n");
	printf("NO textures/test/north.xpm\n");
	printf("SO textures/test/south.xpm\n");
	printf("WE textures/test/west.xpm\n");
	printf("EA textures/test/east.xpm\n");
	printf("\n");
	printf("C 200,200,200\n");
	printf("F 100,200,150\n");
	printf("\n");
	printf("11111\n");
	printf("10001\n");
	printf("10S01\n");
	printf("10001\n");
	printf("10001\n");
	printf("11001\n");
	printf("10001\n");
	printf("10001\n");
	printf("11111\n");
	printf("*****\n\n");
}

bool	cb_check_players(int p)
{
	if (p < 1)
	{
		ft_putstr_fd("Error\nNeeded one player\n", 2);
		return (false);
	}
	if (p > 1)
	{
		ft_putstr_fd("Error\nOnly one player allowed\n", 2);
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
