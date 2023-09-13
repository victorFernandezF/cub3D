/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:22:27 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/13 18:32:11 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	cb_ffe(char **tab, t_point size, t_point begin, int *p);

void	cb_ff1(char **tab, t_point size, t_point begin, int *p)
{
	begin.y = begin.y - 1;
	if (tab[begin.y][begin.x] == 'E')
		(*p)--;
	cb_ff(tab, size, begin, p);
}

void	cb_ff2(char **tab, t_point size, t_point begin, int *p)
{
	begin.y = begin.y + 1;
	if (tab[begin.y][begin.x] == 'E')
		(*p)--;
	cb_ffe(tab, size, begin, p);
}

void	cb_ff3(char **tab, t_point size, t_point begin, int *p)
{
	begin.x = begin.x + 1;
	if (tab[begin.y][begin.x] == 'E')
		(*p)--;
	cb_ff(tab, size, begin, p);
}

void	cb_ff4(char **tab, t_point size, t_point begin, int *p)
{
	begin.x = begin.x - 1;
	if (tab[begin.y][begin.x] == 'E')
		(*p)--;
	cb_ff(tab, size, begin, p);
}

int	cb_ff(char **tab, t_point size, t_point *begin, int *p)
{
	tab[begin->y][begin->x] = 'F';
	if (begin->y - 1 >= 0 && (tab[begin->y - 1][begin->x] == '0'
		|| tab[begin->y - 1][begin->x] == 'E'
		|| tab[begin->y - 1][begin->x] == 'C'))
		sl_ff1(tab, size, begin, p);
	if (begin->y + 1 < size.y && (tab[begin->y + 1][begin->x] == '0'
		|| tab[begin->y + 1][begin->x] == 'E'
		||tab[begin->y + 1][begin->x] == 'C'))
		sl_ff2(tab, size, begin, p);
	if (begin->x + 1 < size.x && (tab[begin->y][begin->x + 1] == '0'
		|| tab[begin->y][begin->x + 1] == 'E'
		|| tab[begin->y][begin->x + 1] == 'C'))
		sl_ff3(tab, size, begin, p);
	if (begin->x - 1 >= 0 && (tab[begin->y][begin->x - 1] == '0'
		|| tab[begin->y][begin->x - 1] == 'E'
		|| tab[begin->y][begin>x - 1] == 'C'))
		sl_ff4(tab, size, begin, p);
	if (*p < 1)
		return (1);
	else
		return (0);
}

