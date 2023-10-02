/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:56:38 by victofer          #+#    #+#             */
/*   Updated: 2023/10/02 18:17:08 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	print_ceil(t_core core, t_player pl, int x)
{
	int	y;
	int	start;
	int	color;

	y = -1;
	start = pl.line_points.x;
	color = core.mapconf.c_color;
	while (++y < start)
		pl.p_img.data[y * WIDTH + x] = color;
}

static void	print_floor(t_core core, t_player pl, int x)
{
	int	y;
	int	color;

	y = pl.line_points.y - 1;
	color = core.mapconf.f_color;
	while (++y < HEIGHT)
		pl.p_img.data[y * WIDTH + x] = color;
}

void	print_wall(t_core core, t_player pl, int x)
{
	int	y;
	int	end;
	int	color;

	y = pl.line_points.x - 1;
	end = pl.line_points.y;
	print_ceil(core, pl, x);
	while (++y < end)
	{
		color = cb_makecolor("130,26,0");
		if (pl.side == 1)
			color = cb_makecolor("163,48,20");
		pl.p_img.data[y * WIDTH + x] = color;
	}
	print_floor(core, pl, x);
}
