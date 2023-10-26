/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:49:39 by fortega-          #+#    #+#             */
/*   Updated: 2023/10/26 12:26:46 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cb_examplefile(void)
{
	printf("\nExample file:\n*****\n");
	printf("NO textures/test/north.xpm\t\\\n");
	printf("SO textures/test/south.xpm\t|\n");
	printf("WE textures/test/west.xpm\t|\n");
	printf("EA textures/test/east.xpm\t|-> Params in the begin\n");
	printf("\t\t\t\t|\n");
	printf("C 200, 200, 200\t\t\t|\n");
	printf("F 100, 200, 150\t\t\t/\n");
	printf("\n");
	printf("11111\t\t\t\t\\\n");
	printf("10001\t\t\t\t|\n");
	printf("10S01\t\t\t\t|\n");
	printf("10001\t\t\t\t|\n");
	printf("10001\t\t\t\t|-> Map at the end\n");
	printf("11001\t\t\t\t|\n");
	printf("10001\t\t\t\t|\n");
	printf("10001\t\t\t\t|\n");
	printf("11111\t\t\t\t/\n");
	printf("\n");
	printf("*****\n\n");
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
