/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:56:38 by victofer          #+#    #+#             */
/*   Updated: 2023/10/25 13:02:38 by victofer         ###   ########.fr       */
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
		pl.p_img.data[y * DWIN_X + x] = color;
	pl.p_img.data[(pl.line.start - 1) * DWIN_X + x] = cb_makecolor("0,0,0");
}

void	print_floor(t_core core, t_player pl, int x)
{
	int	y;
	int	color;

	y = pl.line.end - 1;
	pl.p_img.data[(pl.line.end - 1) * DWIN_X + x] = cb_makecolor("0,0,0");
	color = core.mapconf.f_color;
	while (++y < DWIN_Y)
		pl.p_img.data[y * DWIN_X + x] = color;
}

void	print_texture(t_core core, t_player pl, int x)
{
	t_printtex	tex;
	t_texture	tex_tmp;
	int			y;
	int			end;

	tex = get_texture_datas(pl);
	tex_tmp = get_correct_texture(core, pl);
	y = pl.line.start - 1;
	end = pl.line.end;
	while (++y < end)
	{
		tex.tex_y = (int)tex.texpos;
		tex.texpos += tex.step;
		tex.color = tex_tmp.data[(int)(tex.tex_y * IMGS_X + tex.tex_x)];
		pl.p_img.data[y * DWIN_X + x] = tex.color;
	}
}

void	print_3d_map(t_core core, t_player pl, int x)
{
	print_ceiling(core, pl, x);
	print_texture(core, pl, x);
	print_floor(core, pl, x);
}
