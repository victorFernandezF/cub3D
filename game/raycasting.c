/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:23:39 by victofer          #+#    #+#             */
/*   Updated: 2023/10/17 18:10:15 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_player	get_delta_dist(t_player player)
{
	if (player.ray_dir.x == 0)
		player.delta.x = 1e30;
	else
		player.delta.x = fabs(1 / player.ray_dir.x);
	if (player.ray_dir.y == 0)
		player.delta.y = 1e30;
	else
		player.delta.y = fabs(1 / player.ray_dir.y);
	return (player);
}

static t_player	calculate_side_dsst(t_player player)
{
	if (player.ray_dir.x < 0)
	{
		player.step.x = -1;
		player.side_ds.x = (player.pos.x - player.map.x) * player.delta.x;
	}
	else
	{
		player.step.x = 1;
		player.side_ds.x = (player.map.x + 1.0 - player.pos.x) * player.delta.x;
	}
	if (player.ray_dir.y < 0)
	{
		player.step.y = -1;
		player.side_ds.y = (player.pos.y - player.map.y) * player.delta.y;
	}
	else
	{
		player.step.y = 1;
		player.side_ds.y = (player.map.y + 1.0 - player.pos.y) * player.delta.y;
	}
	return (player);
}

t_player	raycasting(t_player player, char **map)
{
	while (player.hit == 0)
	{
		if (player.side_ds.x < player.side_ds.y)
		{
			player.side_ds.x += player.delta.x;
			player.map.x += player.step.x;
			player.is_side = 0;
			player.side = 'W';
			if (player.map.x - player.pos.x >= 0)
				player.side = 'E';
		}
		else
		{
			player.side_ds.y += player.delta.y;
			player.map.y += player.step.y;
			player.is_side = 1;
			player.side = 'N';
			if (player.map.y - player.pos.y >= 0)
				player.side = 'S';
		}
		if (map[player.map.y][player.map.x] == '1')
			player.hit = 1;
	}
	return (player);
}

t_core	get_texture_data(t_core core)
{
	core.tex_n.ptr = core.imgs.n;
	core.tex_n.data = (int *)mlx_get_data_addr(core.tex_n.ptr, &core.tex_n.bpp,
			&core.tex_n.size_l, &core.tex_n.endian);
	core.tex_s.ptr = core.imgs.s;
	core.tex_s.data = (int *)mlx_get_data_addr(core.tex_s.ptr, &core.tex_s.bpp,
			&core.tex_s.size_l, &core.tex_s.endian);
	core.tex_e.ptr = core.imgs.e;
	core.tex_e.data = (int *)mlx_get_data_addr(core.tex_e.ptr, &core.tex_e.bpp,
			&core.tex_e.size_l, &core.tex_e.endian);
	core.tex_w.ptr = core.imgs.w;
	core.tex_w.data = (int *)mlx_get_data_addr(core.tex_w.ptr, &core.tex_w.bpp,
			&core.tex_w.size_l, &core.tex_w.endian);
	return (core);
}

t_player	rc_start(t_core core)
{
	t_player	player;
	int			x;

	core = get_texture_data(core);
	player = core.player;
	x = -1;
	while (++x < WIDTH)
	{
		player = get_ray_and_positions(player, x);
		player = get_delta_dist(player);
		player = calculate_side_dsst(player);
		player = raycasting(player, core.map);
		player = calculate_wall_dist(player);
		player = calculate_height_line(player);
		print_3d_map(core, player, x);
	}
	mlx_put_image_to_window(core.mlx, core.win, player.p_img.img_ptr, 0, 0);
	return (player);
}
