/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chcek_quadrants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:12:20 by victofer          #+#    #+#             */
/*   Updated: 2023/10/13 13:17:04 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_quadrant_1(t_player pl, char **map)
{
	if (pl.dir.y < 0)
		if (map[(int)(pl.pos.y - 1)][(int)pl.pos.x] == '1')
			if (pl.pos.y >= pl.pos.y - 1 - 0.5)
				return (-1);
	if (pl.dir.y > 0)
		if (map[(int)(pl.pos.y)][(int)pl.pos.x - 1] == '1')
			if (pl.pos.x >= pl.pos.x - 1 - 0.5)
				return (-1);
	return (0);
}

int	check_quadrant_3(t_player pl, char **map)
{
	if (pl.dir.y == 1)
		if (map[(int)(pl.pos.y + 1)][(int)pl.pos.x] == '1')
			if (pl.pos.y == pl.pos.y + 1 - 0.5)
				return (-1);
	if (pl.dir.y > 0)
		if (map[(int)(pl.pos.y)][(int)pl.pos.x - 1] == '1')
			if (pl.pos.x == pl.pos.x - 1 -0.5)
				return (-1);
	return (0);
}
