/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:56:38 by victofer          #+#    #+#             */
/*   Updated: 2023/10/17 19:01:42 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdint.h>

void	print_ceiling(t_core core, t_player pl, int x)
{
	int	y;
	int	start;
	int	color;

	y = 0;
	start = pl.line.start;
	color = core.mapconf.c_color;
	while (++y < start)
		pl.p_img.data[y * WIDTH + x] = color;
	pl.p_img.data[(pl.line.start - 1) * WIDTH + x] = cb_makecolor("0,0,0");
}

void	print_floor(t_core core, t_player pl, int x)
{
	int	y;
	int	color;

	y = pl.line.end - 1;
	pl.p_img.data[(pl.line.end - 1) * WIDTH + x] = cb_makecolor("0,0,0");
	color = core.mapconf.f_color;
	while (++y < HEIGHT)
		pl.p_img.data[y * WIDTH + x] = color;
}

int	get_color_of_texture(t_core core, t_player pl, int x, int y)
{
	int			tex_x;
	int			tex_y;
	int			color;
	t_texture	tex_tmp;

	color = 1;
	if (pl.side == 'N')
		tex_tmp = core.tex_n;
	if (pl.side == 'S')
		tex_tmp = core.tex_s;
	if (pl.side == 'E')
		tex_tmp = core.tex_e;
	if (pl.side == 'W')
		tex_tmp = core.tex_w;
	tex_x = x % tex_tmp.size_l;
	tex_y = y % tex_tmp.bpp;
	color = *(int *)(tex_tmp.data + (tex_y
				* tex_tmp.size_l) + (tex_x * (tex_tmp.bpp / 8)));
	return (color);
}

void	print_texture(t_core core, t_player pl, int x)
{
	int				y;
	int				end;
	unsigned int	color;

	y = pl.line.start - 1;
	end = pl.line.end;
	while (++y < end)
	{
		color = get_color_of_texture(core, pl, x, y);
		pl.p_img.data[y * WIDTH + x] = color;
	}
}

void	print_3d_map(t_core core, t_player pl, int x)
{
	print_ceiling(core, pl, x);
	print_texture(core, pl, x);
	print_floor(core, pl, x);
}
