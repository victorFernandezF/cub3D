/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:23:39 by victofer          #+#    #+#             */
/*   Updated: 2023/09/29 10:59:02 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		//printf("%s NO %s\n", C, W);
		player.step.x = -1;
		player.side_di.x = (player.pos.x + player.map.x) * player.delta.x;
	}
	else
	{
		player.step.x = 1;
		player.side_di.x = (player.map.x + 1.0 - player.pos.x) * player.delta.x;
/* 		printf("%s MAP X: %i %s\n", C, player.map.x, W);
		printf("%s SIDE POS X: %.2f %s\n", C, player.pos.x, W);
		printf("%s SIDE DIST X: %.2f %s\n", C, player.side_di.x, W); */
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
		{
			player.hit = 1;
		}
	}
	return (player);
}

t_core	rc_start(t_core core)
{
	int			x;

	x = 0;
	//core.player.img = mlx_new_image(core.mlx, DWIN_X, DWIN_Y);
	while (x < WIDTH)
	{
		core.player = calculate_position(core.player, x);
		core.player = calculate_delta_stuff(core.player);
		core.player = calculate_side_dist(core.player);
		core.player = dda_algorithm(core.player, core.map);
		core.player = calculate_wall_dist(core.player);
		core.player = calculate_height_line(core.player);
		core = print_wall(core, x);
		x++;
	}
	//mlx_put_image_to_window(core.mlx, core.win, core.player.img, 0, 0);
	return (core);
}
