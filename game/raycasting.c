/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:23:39 by victofer          #+#    #+#             */
/*   Updated: 2023/09/27 12:10:42 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_player	calculate_initial_ray_dir(t_player player, double cam)
{
	player.ray_dir.x = player.direction.x + player.plane.x * cam;
	player.ray_dir.y = player.direction.y + player.plane.y * cam;
	player.map_pos.x = player.grid_coord.x;
	player.map_pos.y = player.grid_coord.y;
	player.hit = 0;
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

static t_player	dda_algorithm(t_player player, char **map)
{
	int	hit;

	hit = player.hit;
	while (hit == 0)
	{
		if (player.side_dist.x < player.side_dist.y)
		{
			player.side_dist.x += player.delta_dist.x;
			player.map_pos.x += player.step.x;
			player.side = 0;
		}
		else
		{
			player.side_dist.y += player.delta_dist.y;
			player.map_pos.y += player.step.y;
			player.side = 1;
		}
		if (map[player.map_pos.x][player.map_pos.y] == '1')
		{
			player.hit = 1;
			hit += 1;
		}
	}
	return (player);
}

t_core	rc_start(t_core core)
{
	int			i;
	double		cam_x;

	core.player.img = mlx_new_image(core.mlx, DWIN_X, DWIN_Y);
	i = -1;
	while (++i < core.mapconf.map_x)
	{
		cam_x = 2 * i / (double)core.mapconf.map_x - 1;
		core.player = calculate_initial_ray_dir(core.player, cam_x);
		core.player = calculate_delta_stuff(core.player);
		core.player = calculate_side_dist(core.player);
		core.player = dda_algorithm(core.player, core.map);
		core.player = calculate_wall_dist(core.player);
		core.player = calculate_height_line(core.player);
		//printf("color: %i\n", core.mapconf.c_color);
		//print_wall(core, i);
		//mlx_put_image_to_window(core.mlx, core.win, core.player.img, DWIN_X, DWIN_Y);
	}
	return (core);
}
