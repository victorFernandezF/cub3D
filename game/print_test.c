/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:29:43 by victofer          #+#    #+#             */
/*   Updated: 2023/10/02 11:29:46 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_player_stuff(t_player player)
{
	printf("%s   PLAYER STUFF   \n", G);
	printf(" player char  [%c]\n", player.player);
	printf(" player height  (%i)\n", player.height);
	printf(" player grid pos  (%.2f, %.2f)\n",
		player.grid_coord.x, player.grid_coord.y);
	printf(" player real pos (%.2f, %.2f)\n",
		player.pos.x, player.pos.y);
	printf(" player direction (%.2f, %.2f)\n",
		player.direction.x, player.direction.y);
	printf(" player plane (%.2f, %.2f)%s\n",
		player.plane.x, player.plane.y, G);
	printf(" player cam_start(%.2f, %.2f)%s\n",
		player.cam_start.x, player.cam_start.y, G);
	printf(" player cam_end(%.2f, %.2f)%s\n",
		player.cam_end.x, player.cam_end.y, G);
	printf(" player map pos(%i, %i)%s\n",
		player.map.x, player.map.y, G);
	printf(" player ray dir(%.2f, %.2f)%s\n",
		player.ray_dir.x, player.ray_dir.y, G);
	printf(" player side dist(%.2f, %.2f)%s\n",
		player.side_di.x, player.side_di.y, G);
	printf(" player delta dist(%.2f, %.2f)%s\n",
		player.delta.x, player.delta.y, G);
	printf(" player step(%i, %i)%s\n",
		player.step.x, player.step.y, G);	
	printf(" player wall dist (%.2f)%s\n",
		player.wall_dist, G);
	printf(" player line height(%i,%i)%s\n",
		player.line_points.x, player.line_points.y, G);
	printf(" player line points (%i, %i)%s\n\n",
		player.line_points.x, player.line_points.y, W);
}