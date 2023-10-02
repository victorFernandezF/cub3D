/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:23:39 by victofer          #+#    #+#             */
/*   Updated: 2023/10/02 12:42:03 by victofer         ###   ########.fr       */
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
		{
			player.hit = 1;
		}
	}
	return (player);
}

t_player	rc_start(t_core core)
{
	t_player	player;
	int			x;

	x = 0;
	player = init_player_datas(core);

	//core.player.img = mlx_new_image(core.mlx, WIDTH, HEIGHT);
	while (x < WIDTH)
	{
		player = calculate_position(player, x);
		player = calculate_delta_stuff(player);
		player = calculate_side_dist(player);
		player = dda_algorithm(player, core.map);
		player = calculate_wall_dist(player);
		player = calculate_height_line(player);
		print_wall(core, player, x);
		x++;
	}
	//mlx_put_image_to_window(core.mlx, core.win, core.player.img, 0, 0);
	return (player);
}
