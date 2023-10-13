/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:56:38 by victofer          #+#    #+#             */
/*   Updated: 2023/10/13 12:10:08 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdint.h>

void	print_ceiling(t_core core, t_player pl, int x)
{
	int	y;
	int	start;
	int	color;

	y = -1;
	start = pl.line.start;
	color = core.mapconf.c_color;
	while (++y < start)
		pl.p_img.data[y * WIDTH + x] = color;
}

void	print_floor(t_core core, t_player pl, int x)
{
	int	y;
	int	color;

	y = pl.line.end - 1;
	color = core.mapconf.f_color;
	while (++y < HEIGHT)
		pl.p_img.data[y * WIDTH + x] = color;
}

void	print_3d_map(t_core core, t_player pl, int x)
{
	int			y;
	int			end;
	int			color;

	y = pl.line.start - 1;
	end = pl.line.end;
	print_ceiling(core, pl, x);
	while (++y < end)
	{
		color = cb_makecolor("3,25,140");
		if (pl.is_side == 1)
			color = cb_makecolor("24,59,237");
		pl.p_img.data[y * WIDTH + x] = color;
	}
	print_floor(core, pl, x);
}
//side 0 rayx big 0 -> texx = Width - texx -1
