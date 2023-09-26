/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:23:39 by victofer          #+#    #+#             */
/*   Updated: 2023/09/26 10:49:55 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_player	calculate_initial_ray_dir(t_player player, double cam)
{
	player.ray_dir.x = player.direction.x + player.plane.x * cam;
	player.ray_dir.y = player.direction.y + player.plane.y * cam;
	player.map_pos.x = player.grid_coord.x;
	player.map_pos.y = player.grid_coord.y;
	return (player);
}

static t_player	calculate_delta_stuff(t_player player)
{
	if (player.ray_dir.x == 0 || player.ray_dir.y == 0)
	{
		if (player.ray_dir.x == 0)
			player.delta_dist.x = 1e30;
		if (player.ray_dir.y == 0)
			player.delta_dist.y = 1e30;
	}
	else
	{
		player.delta_dist.x = fabs(1 / player.ray_dir.x);
		player.delta_dist.y = fabs(1 / player.ray_dir.y);
	}
	return (player);
}

static t_player	calculate_side_dist(t_player player)
{
	if (player.ray_dir.x < 0)
	{
		player.step.x = -1;
		player.side_dist.x = (player.position.x + player.map_pos.x)
			* player.delta_dist.x;
	}
	else
	{
		player.step.x = 1;
		player.side_dist.x = (player.map_pos.x + 1.0 - player.position.x)
			* player.delta_dist.x;
	}
	if (player.ray_dir.y < 0)
	{
		player.step.y = -1;
		player.side_dist.y = (player.position.y + player.map_pos.y)
			* player.delta_dist.x;
	}
	else
	{
		player.step.y = 1;
		player.side_dist.y = (player.map_pos.y + 1.0 - player.position.y)
			* player.delta_dist.y;
	}
	return (player);
}

t_player	rc_start(t_player player, t_mapconf map)
{
	int			i;
	double		cam_x;

	i = -1;
	while (++i < map.map_x)
	{
		cam_x = 2 * i / (double)map.map_x - 1;
		player = calculate_initial_ray_dir(player, cam_x);
		player = calculate_delta_stuff(player);
		player = calculate_side_dist(player);
		//printf("test side: %.2f\n", player.side_dist.x);
	}
	return (player);
}
