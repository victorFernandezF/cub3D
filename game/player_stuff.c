/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:09:29 by victofer          #+#    #+#             */
/*   Updated: 2023/09/20 19:39:32 by victofer         ###   ########.fr       */
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

	x = core.player.position.x;
	y = core.player.position.y;
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

t_core init_player_datas(t_core core){
	core.player.height = 32;
	core.player.vision_grade = 60;
	core.player.position.x = get_pos(core.mapconf, core.map, 'x');
	core.player.position.y = get_pos(core.mapconf, core.map, 'y');
	core.player.grade_orientation = get_grade(core);
	printf("grade %i\n", core.player.grade_orientation);
	return (core);
}