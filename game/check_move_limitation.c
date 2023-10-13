/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move_limitation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:44:52 by victofer          #+#    #+#             */
/*   Updated: 2023/10/13 13:25:22 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	find_next_top_wall(char **map, t_player pl)
{
	int	y;

	y = pl.pos.y;
	while (map[y])
	{
		if (map[y][(int)pl.pos.x] == '1')
			return ((double)y);
		y--;
	}
	return (0);
}

int	get_quadrant(t_player pl)
{
	if ((pl.dir.x >= -1 && pl.dir.x <= 0)
		&& (pl.dir.y >= -1 && pl.dir.y <= 0.03))
		return (1);
	if ((pl.dir.x >= 0 && pl.dir.x <= 1)
		&& (pl.dir.y >= -1 && pl.dir.y <= 0.03))
		return (2);
	if ((pl.dir.x >= -1 && pl.dir.x <= 0.06)
		&& (pl.dir.y >= 0.03 && pl.dir.y <= 1))
		return (3);
	if ((pl.dir.x >= 0.06 && pl.dir.x <= 1)
		&& (pl.dir.y >= 0.03 && pl.dir.y <= 1))
		return (4);
	return (-1);
}

int	check_limit_front(t_player pl, char **map)
{
	int	cuad;
	int	res;

	res = 0;
	cuad = get_quadrant(pl);
	if (cuad == 1)
		check_quadrant_1(pl, map);
	if (cuad == 3)
		check_quadrant_3(pl, map);
	return (res);
}

/* 	printf("%f (%i, %i) %c\n", pl.dir.y, (int)(pl.pos.y + 1), (int)pl.pos.x,
		map[(int)(pl.pos.y + 1)][(int)pl.pos.x]); */
int	check_limit_back(t_player pl, char **map)
{
	if (pl.dir.y < 0)
		if (map[(int)(pl.pos.y + 1)][(int)pl.pos.x] == '1')
			return (-1);
	if (pl.dir.y > 0)
		if (map[(int)(pl.pos.y - 1)][(int)pl.pos.x] == '1')
			return (-1);
	if (pl.dir.x < 0)
		if (map[(int)(pl.pos.y)][(int)pl.pos.x + 1] == '1')
			return (-1);
	if (pl.dir.x > 0)
		if (map[(int)(pl.pos.y)][(int)pl.pos.x - 1] == '1')
			return (-1);
	return (0);
}
