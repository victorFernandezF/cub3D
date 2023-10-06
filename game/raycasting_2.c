/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:25:59 by victofer          #+#    #+#             */
/*   Updated: 2023/10/06 12:39:51 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_player	get_ray_and_positions(t_core core, t_player player, int x)
{
	(void)core;
/* 	player.grid_coord.x = get_pos(core.mapconf, core.map, 'x');
	player.grid_coord.y = get_pos(core.mapconf, core.map, 'y');
	player.pos.x = player.grid_coord.x + 0.5;
	player.pos.y = player.grid_coord.y + 0.5; */
	player.cam.x = 2 * x / (double) WIDTH - 1;
	player.ray_dir.x = player.dir.x + player.plane.x * player.cam.x;
	player.ray_dir.y = player.dir.y + player.plane.y * player.cam.x;
	player.map.x = (int)player.pos.x;
	player.map.y = (int)player.pos.y;
	player.hit = 0;
	return (player);
}

t_player	calculate_wall_dist(t_player player)
{
	if (player.is_side == 0)
		player.line.wall_dist = (player.side_ds.x - player.delta.x);
	else
		player.line.wall_dist = (player.side_ds.y - player.delta.y);
	return (player);
}

t_player	calculate_height_line(t_player player)
{
	player.line.height = (int)(HEIGHT / player.line.wall_dist);
	player.line.start = -player.line.height / 2 + HEIGHT / 2;
	if (player.line.start < 0)
		player.line.start = 0;
	player.line.end = player.line.height / 2 + HEIGHT / 2;
	if (player.line.end > HEIGHT)
		player.line.end = HEIGHT - 1;
	return (player);
}
