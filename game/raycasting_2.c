/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:25:59 by victofer          #+#    #+#             */
/*   Updated: 2023/09/28 13:13:46 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_player	calculate_wall_dist(t_player player)
{
	if (player.side == 0)
	{
		player.wall_dist = (player.side_di.x - player.delta.x);
	}
	else
	{
		player.wall_dist = (player.side_di.y - player.delta.y);
	}
	return (player);
}

t_player	calculate_height_line(t_player player)
{
	player.line_height = (int)(HEIGHT / player.wall_dist);
	player.line_points.x = (player.line_height * -1) / 2 + HEIGHT / 2;
	if (player.line_points.x < 0)
		player.line_points.x = 0;
	player.line_points.y = player.line_height / 2 + HEIGHT / 2;
	if (player.line_points.y >= HEIGHT)
		player.line_points.y = HEIGHT - 1;
	return (player);
}

t_core	print_wall(t_core core, int i)
{
	int	y;
	int	end;

	y = 0;
	y = core.player.line_points.x;
	end = core.player.line_points.y;
	printf("line %i/%d\n", y, end);
	while (y < end)
	{
		printf("pixel (%i, %i)\n", i, y);
		mlx_pixel_put(core.mlx, core.win, i, y, 10079487);
		y++;
	}
	return (core);
}
