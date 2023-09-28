/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:23:39 by victofer          #+#    #+#             */
/*   Updated: 2023/09/28 13:12:42 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_player	calculate_initial_ray_dir(t_player player, double cam)
{
	player.ray_dir.x = player.direction.x + player.plane.x * cam;
	player.ray_dir.y = player.direction.y + player.plane.y * cam;
	player.map.x = player.grid_coord.x;
	player.map.y = player.grid_coord.y;
	player.hit = 0;
	return (player);
}

static t_player	calculate_delta_stuff(t_player player)
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

static t_player	calculate_side_dist(t_player player)
{
	if (player.ray_dir.x < 0)
	{
		player.step.x = -1;
		player.side_di.x = (player.pos.x + player.map.x) * player.delta.x;
	}
	else
	{
		player.step.x = 1;
		player.side_di.x = (player.map.x + 1.0 - player.pos.x) * player.delta.x;
	}
	if (player.ray_dir.y < 0)
	{
		player.step.y = -1;
		player.side_di.y = (player.pos.y + player.map.y) * player.delta.y;
	}
	else
	{
		player.step.y = 1;
		player.side_di.y = (player.map.y + 1.0 - player.pos.y) * player.delta.y;
	}
	return (player);
}

static t_player	dda_algorithm(t_player player, char **map)
{
	while (player.hit == 0)
	{
		if (player.side_di.x < player.side_di.y)
		{
			player.side_di.x += player.delta.x;
			player.map.x += player.step.x;
			player.side = 0;
		}
		else
		{
			player.side_di.y += player.delta.y;
			player.map.y += player.step.y;
			player.side = 1;
		}
		if (map[player.map.y][player.map.x] == '1')
			player.hit = 1;
	}
	return (player);
}

t_core	rc_start(t_core core)
{
	int			x;
	double		cam_x;

	x = -1;
	core.player.img = mlx_new_image(core.mlx, DWIN_X, DWIN_Y);
	while (++x < WIDTH)
	{
		cam_x = 2 * x / (double) HEIGHT - 1;
		core.player = calculate_initial_ray_dir(core.player, cam_x);
		core.player = calculate_delta_stuff(core.player);
		core.player = calculate_side_dist(core.player);
		core.player = dda_algorithm(core.player, core.map);
		core.player = calculate_wall_dist(core.player);
		core.player = calculate_height_line(core.player);
		core = print_wall(core, x);
		//printf("Test: %c\n", core.player.player); //mapconf.c_color);
	}
	mlx_put_image_to_window(core.mlx, core.win, core.player.img, 0, 0);
	return (core);
}
