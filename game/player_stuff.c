/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:09:29 by victofer          #+#    #+#             */
/*   Updated: 2023/09/21 12:04:05 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int is_player(char c)
{
	return (c == 'N' || c == 'W' || c == 'S' || c == 'E');
}

static int get_pos(t_mapconf mapconf, char **map, char pos)
{
	int i;
	int j;
	int x;
	int y;

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

int get_grade(t_core core){
	int x;
	int y;

	x = core.player.grid_coord.x;
	y = core.player.grid_coord.y;
	if (core.map[y][x] == 'E')
		return (0);
	if (core.map[y][x] == 'N')
		return (90);
	if (core.map[y][x] == 'W')
		return (180);
	if (core.map[y][x] == 'S')
		return (270);
	return (-1);
}

static void print_player_stuff(t_core core){
	
	printf("%splayer height  (%i)\n", G, core.player.height);
	printf("player vision grade  (%i)\n", core.player.vision_grade);
	printf("player grid pos  (%i, %i)\n", core.player.grid_coord.x, core.player.grid_coord.y);
	printf("player real pos  (%i, %i)\n", core.player.position.x, core.player.position.y);
	printf("player grade (%i)%s\n", core.player.grade_orientation, W);
} 

t_core init_player_datas(t_core core){
	core.player.height = IMGS_Y / 2;
	core.player.vision_grade = 60;
	core.player.grid_coord.x = get_pos(core.mapconf, core.map, 'x');
	core.player.grid_coord.y = get_pos(core.mapconf, core.map, 'y');
	core.player.position.x = (IMGS_X * core.player.grid_coord.x) + IMGS_X / 2;
	core.player.position.y = (IMGS_Y * core.player.grid_coord.y) + IMGS_Y / 2;
	core.player.grade_orientation = get_grade(core);
	print_player_stuff(core);
	
	return (core);
}