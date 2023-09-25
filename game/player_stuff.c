/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:09:29 by victofer          #+#    #+#             */
/*   Updated: 2023/09/25 11:13:55 by victofer         ###   ########.fr       */
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

t_core	get_degree(t_core core, int x, int y)
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

static void	print_player_stuff(t_core core)
{
	printf("%s   PLAYER STUFF   \n", G);
	printf(" player char  [%c]\n", core.player.player);
	printf(" player height  (%i)\n", core.player.height);
	printf(" player vision degree  (%i)\n", core.player.vision_degree);
	printf(" player grid pos  (%.2f, %.2f)\n",
		core.player.grid_coord.x, core.player.grid_coord.y);
	printf(" player real pos (%.2f, %.2f)\n",
		core.player.position.x, core.player.position.y);
	printf(" player direction (%.2f, %.2f)\n",
		core.player.direction.x, core.player.direction.y);
	printf(" player degree (%i)\n", core.player.orientation_degree);
	printf(" player plane (%.2f, %.2f)%s\n\n",
		core.player.plane.x, core.player.plane.y, W);
}

t_core	init_player_datas(t_core core)
{
	int	x;
	int	y;

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
	core.player.position.x = (IMGS_X * core.player.grid_coord.x) + IMGS_X / 2;
	core.player.position.y = (IMGS_Y * core.player.grid_coord.y) + IMGS_Y / 2;
	core = get_degree(core, x, y);
	print_player_stuff(core);
	return (core);
}
