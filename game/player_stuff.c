/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:09:29 by victofer          #+#    #+#             */
/*   Updated: 2023/09/29 11:45:25 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/cub3d.h"

static int	is_player(char c)
{
	return (c == 'N' || c == 'W' || c == 'S' || c == 'E');
}

static int	get_pos(t_mapconf mapconf, char **map, char pos)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	x = 0;
	y = 0;
	while (++i < mapconf.map_x)
	{
		j = -1;
		while (++j < mapconf.map_y)
		{
			if (is_player(map[i][j]))
			{
				x = j;
				y = i;
			}
		}
	}
	if (pos == 'x')
		return (x);
	return (y);
}

static t_core	get_plane(t_core core, int x, int y)
{
	if (core.map[y][x] == 'E')
	{
		core.player.orientation_degree = 0;
		core.player.direction.x = 1;
		core.player.plane.y = 0.66;
	}
	if (core.map[y][x] == 'N')
	{
		core.player.orientation_degree = 90;
		core.player.direction.y = -1;
		core.player.plane.x = 0.66;
	}
	if (core.map[y][x] == 'W')
	{
		core.player.orientation_degree = 180;
		core.player.direction.x = -1;
		core.player.plane.y = -0.66;
	}
	if (core.map[y][x] == 'S')
	{
		core.player.orientation_degree = 270;
		core.player.direction.y = 1;
		core.player.plane.x = -0.66;
	}
	return (core);
}

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

t_core	init_player_datas(t_core core)
{
	int	x;
	int	y;

	core.player.line_height = 0;
	core.player.line_points.x = 0;
	core.player.line_points.y = 0;
	core.player.plane.x = 0;
	core.player.plane.y = 0;
	core.player.direction.x = 0;
	core.player.direction.y = 0;
	core.player.height = IMGS_Y / 2;
	core.player.vision_degree = 66;
	core.player.grid_coord.x = get_pos(core.mapconf, core.map, 'x');
	core.player.grid_coord.y = get_pos(core.mapconf, core.map, 'y');
	x = core.player.grid_coord.x;
	y = core.player.grid_coord.y;
	core.player.player = core.map[y][x];
	core.player.pos.x = core.player.grid_coord.x + 0.1;
	core.player.pos.y = core.player.grid_coord.y + 0.1;
	core = get_plane(core, x, y);
	core = get_cam(core);
	return (core);
}
