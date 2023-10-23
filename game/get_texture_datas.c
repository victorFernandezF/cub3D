/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_datas.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:58:38 by victofer          #+#    #+#             */
/*   Updated: 2023/10/23 11:39:10 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_texture	get_correct_texture(t_core core, t_player pl)
{
	t_texture	tex_tmp;

	if (pl.side == 'N')
		tex_tmp = core.tex_n;
	if (pl.side == 'S')
		tex_tmp = core.tex_s;
	if (pl.side == 'E')
		tex_tmp = core.tex_e;
	if (pl.side == 'W')
		tex_tmp = core.tex_w;
	return (tex_tmp);
}

t_printtex	get_texture_datas(t_player pl)
{
	t_printtex	tex;

	if (pl.is_side == 0)
		tex.wallx = pl.pos.y + pl.line.wall_dist * pl.ray_dir.y;
	else
		tex.wallx = pl.pos.x + pl.line.wall_dist * pl.ray_dir.x;
	tex.wallx -= floor(tex.wallx);
	tex.tex_x = (int)(tex.wallx * (double)IMGS_X);
	if (pl.is_side == 0 && pl.ray_dir.x > 0)
		tex.tex_x = IMGS_X - tex.tex_x - 1;
	if (pl.is_side == 1 && pl.ray_dir.y < 0)
			tex.tex_x = IMGS_X - tex.tex_x - 1;
	tex.step = 1.0 * IMGS_X / pl.line.height;
	tex.texpos = (pl.line.start - DWIN_Y / 2 + pl.line.height / 2) * tex.step;	
	return (tex);
}
