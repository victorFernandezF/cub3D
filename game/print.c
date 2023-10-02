/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:56:38 by victofer          #+#    #+#             */
/*   Updated: 2023/10/02 13:56:45 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	print_ceil(t_core core, t_player pl, int x)
{
	int	y;
	int	start;
	int	color;

	y = 0;
	start = pl.line_points.x;
	color = core.mapconf.c_color;
	while (y < start)
	{
		mlx_pixel_put(core.mlx, core.win, x, y, color);
		y++;
	}
}

static void	print_floor(t_core core, t_player pl, int x)
{
	int	y;
	int	color;

	y = pl.line_points.y;
	color = core.mapconf.f_color;
	while (y < HEIGHT)
	{
		mlx_pixel_put(core.mlx, core.win, x, y, color);
		y++;
	}
}

void	print_wall(t_core core, t_player pl, int x)
{
	int	y;
	int	end;
	int	color;

	y = 0;
	y = pl.line_points.x;
	end = pl.line_points.y;
	print_ceil(core, pl, x);
	while (y < end)
	{
		color = cb_makecolor("130,26,0");
		if (pl.side == 1)
			color = cb_makecolor("163,48,20");
		mlx_pixel_put(core.mlx, core.win, x, y, color);
		y++;
	}
	print_floor(core, pl, x);
}
