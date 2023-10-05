/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:17:40 by victofer          #+#    #+#             */
/*   Updated: 2023/10/05 19:19:39 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_core	*move_character(t_core *core, double old_x, double old_y)
{
	double	x;
	double	y;

	x = core->player.pos.x + old_x * MSPEED;
	y = core->player.pos.y + old_y * MSPEED;
	if (core->map[(int)core->player.pos.y]
		[(int)(x + core->player.direction.x / 1e5)] != '1')
			core->player.pos.x = x;
	if (core->map[(int)(y + core->player.direction.y / 1e5)]
		[(int)core->player.pos.x] != '1')
			core->player.pos.y = y;
	return (core);
}

int	input(int key, t_core *core)
{
	t_player	*pl;

	pl = &core->player;
	if (key == 53)
		cb_exit(core);
	if (key == 13)
	{
		if (core->map[(int)pl->pos.y][(int)pl->pos.x] == '1')
			return (0);
		core = move_character(core, pl->direction.x, pl->direction.y);
	}
	if (key == 1)
	{
		if (core->map[(int)pl->pos.y][(int)pl->pos.x] == '1')
			return (0);
		core = move_character(core, pl->direction.x, -pl->direction.y);
	}
	core->player = rc_start(*core);
	return (0);
}
