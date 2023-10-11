/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move_limitation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:44:52 by victofer          #+#    #+#             */
/*   Updated: 2023/10/11 18:12:45 by victofer         ###   ########.fr       */
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

int	check_limit_front(t_player pl, char **map)
{
	if (pl.dir.y < 0)
		if (map[(int)(pl.pos.y - 1)][(int)pl.pos.x] == '1')
			return (-1);
	if (pl.dir.y > 0)
		if (map[(int)(pl.pos.y + 1)][(int)pl.pos.x] == '1')
			return (-1);
	if (pl.dir.x < 0)
		if (map[(int)(pl.pos.y)][(int)pl.pos.x - 1] == '1')
			return (-1);
	if (pl.dir.x > 0)
		if (map[(int)(pl.pos.y)][(int)pl.pos.x + 1] == '1')
			return (-1);
	return (0);
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
