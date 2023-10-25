/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:25:59 by victofer          #+#    #+#             */
/*   Updated: 2023/10/25 11:04:20 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_player	get_ray_and_positions(t_player player, int x)
{
	player.cam_x = 2 * x / (double) DWIN_X - 1;
	player.ray_dir.x = player.dir.x + player.plane.x * player.cam_x;
	player.ray_dir.y = player.dir.y + player.plane.y * player.cam_x;
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
	player.line.height = (int)(DWIN_Y / player.line.wall_dist);
	player.line.start = -player.line.height / 2 + DWIN_Y / 2;
	if (player.line.start < 0)
		player.line.start = 0;
	player.line.end = player.line.height / 2 + DWIN_Y / 2;
	if (player.line.end >= DWIN_Y)
		player.line.end = DWIN_Y - 1;
	return (player);
}
