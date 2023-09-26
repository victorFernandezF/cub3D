/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:25:59 by victofer          #+#    #+#             */
/*   Updated: 2023/09/26 12:53:44 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_player	calculate_wall_dist(t_player player)
{
	if (player.side == 0)
		player.wall_dist = player.side_dist.x - player.delta_dist.x;
	else
		player.wall_dist = player.side_dist.y - player.delta_dist.y;
	return (player);
}

t_player	calculate_height_line(t_player player)
{
	int	line_start;
	int	line_end;

	player.line_height = (int)(DWIN_Y / player.wall_dist);
	line_start = -player.line_height / 2 + DWIN_Y / 2;
	if (line_start < 0)
		player.line_points.x = 0;
	line_end = player.line_height / 2 + DWIN_Y / 2;
	if (line_start >= DWIN_Y)
		player.line_points.y = DWIN_Y - 1;
	return (player);
}
