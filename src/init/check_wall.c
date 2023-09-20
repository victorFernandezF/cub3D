/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:22:27 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/20 08:49:38 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cb_ff(char **tab, t_point size, t_point begin, int *f);

void	cb_ff1(char **tab, t_point size, t_point begin, int *f)
{
	begin.y = begin.y - 1;
	if (begin.y == 0 || (begin.y - 1 >= 0 && (tab[begin.y - 1][begin.x] != '0'
			&& tab[begin.y - 1][begin.x] != '1'
		&& tab[begin.y - 1][begin.x] != 'F')))
		(*f)++;
	if (begin.y == size.y - 1
		|| (begin.y + 1 <= size.y && (tab[begin.y + 1][begin.x] != '0'
			&& tab[begin.y + 1][begin.x] != '1'
		&& tab[begin.y + 1][begin.x] != 'F')))
		(*f)++;
	if (begin.x == size.x - 1
		|| (begin.x + 1 <= size.x && (tab[begin.y][begin.x + 1] != '0'
			&& tab[begin.y][begin.x + 1] != '1'
		&& tab[begin.y][begin.x + 1] != 'F')))
		(*f)++;
	if (begin.x == 0
		|| (begin.x - 1 >= 0 && (tab[begin.y][begin.x - 1] != '0'
			&& tab[begin.y][begin.x - 1] != '1'
		&& tab[begin.y][begin.x - 1] != 'F')))
		(*f)++;
	cb_ff(tab, size, begin, f);
}

void	cb_ff2(char **tab, t_point size, t_point begin, int *f)
{
	begin.y = begin.y + 1;
	if (begin.y == 0 || (begin.y - 1 >= 0 && (tab[begin.y - 1][begin.x] != '0'
			&& tab[begin.y - 1][begin.x] != '1'
		&& tab[begin.y - 1][begin.x] != 'F')))
		(*f)++;
	if (begin.y == size.y - 1
		|| (begin.y + 1 <= size.y && (tab[begin.y + 1][begin.x] != '0'
			&& tab[begin.y + 1][begin.x] != '1'
		&& tab[begin.y + 1][begin.x] != 'F')))
		(*f)++;
	if (begin.x == size.x - 1
		|| (begin.x + 1 <= size.x && (tab[begin.y][begin.x + 1] != '0'
			&& tab[begin.y][begin.x + 1] != '1'
		&& tab[begin.y][begin.x + 1] != 'F')))
		(*f)++;
	if (begin.x == 0
		|| (begin.x - 1 >= 0 && (tab[begin.y][begin.x - 1] != '0'
			&& tab[begin.y][begin.x - 1] != '1'
		&& tab[begin.y][begin.x - 1] != 'F')))
		(*f)++;
	cb_ff(tab, size, begin, f);
}

void	cb_ff3(char **tab, t_point size, t_point begin, int *f)
{
	begin.x = begin.x + 1;
	if (begin.y == 0 || (begin.y - 1 >= 0 && (tab[begin.y - 1][begin.x] != '0'
			&& tab[begin.y - 1][begin.x] != '1'
		&& tab[begin.y - 1][begin.x] != 'F')))
		(*f)++;
	if (begin.y == size.y - 1
		|| (begin.y + 1 <= size.y && (tab[begin.y + 1][begin.x] != '0'
			&& tab[begin.y + 1][begin.x] != '1'
		&& tab[begin.y + 1][begin.x] != 'F')))
		(*f)++;
	if (begin.x == size.x - 1
		|| (begin.x + 1 <= size.x && (tab[begin.y][begin.x + 1] != '0'
			&& tab[begin.y][begin.x + 1] != '1'
		&& tab[begin.y][begin.x + 1] != 'F')))
		(*f)++;
	if (begin.x == 0
		|| (begin.x - 1 >= 0 && (tab[begin.y][begin.x - 1] != '0'
			&& tab[begin.y][begin.x - 1] != '1'
		&& tab[begin.y][begin.x - 1] != 'F')))
		(*f)++;
	cb_ff(tab, size, begin, f);
}

void	cb_ff4(char **tab, t_point size, t_point begin, int *f)
{
	begin.x = begin.x - 1;
	if (begin.y == 0 || (begin.y - 1 >= 0 && (tab[begin.y - 1][begin.x] != '0'
			&& tab[begin.y - 1][begin.x] != '1'
		&& tab[begin.y - 1][begin.x] != 'F')))
		(*f)++;
	if (begin.y == size.y - 1
		|| (begin.y + 1 <= size.y && (tab[begin.y + 1][begin.x] != '0'
			&& tab[begin.y + 1][begin.x] != '1'
		&& tab[begin.y + 1][begin.x] != 'F')))
		(*f)++;
	if (begin.x == size.x - 1
		|| (begin.x + 1 <= size.x && (tab[begin.y][begin.x + 1] != '0'
			&& tab[begin.y][begin.x + 1] != '1'
		&& tab[begin.y][begin.x + 1] != 'F')))
		(*f)++;
	if (begin.x == 0
		|| (begin.x - 1 >= 0 && (tab[begin.y][begin.x - 1] != '0'
			&& tab[begin.y][begin.x - 1] != '1'
		&& tab[begin.y][begin.x - 1] != 'F')))
		(*f)++;
	cb_ff(tab, size, begin, f);
}

void	cb_ff(char **tab, t_point size, t_point begin, int *f)
{
	tab[begin.y][begin.x] = 'F';
	if (begin.y - 1 >= 0 && (tab[begin.y - 1][begin.x] == '0'))
	{
		cb_ff1(tab, size, begin, f);
	}
	if (begin.y + 1 < size.y && (tab[begin.y + 1][begin.x] == '0'))
	{
		cb_ff2(tab, size, begin, f);
	}
	if (begin.x + 1 < size.x && (tab[begin.y][begin.x + 1] == '0'))
	{
		cb_ff3(tab, size, begin, f);
	}
	if (begin.x - 1 >= 0 && (tab[begin.y][begin.x - 1] == '0'))
	{
		cb_ff4(tab, size, begin, f);
	}
}

