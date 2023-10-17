/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:20:40 by victofer          #+#    #+#             */
/*   Updated: 2023/10/17 18:15:31 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Move the player one spet forward (if there are no walls)
t_core	*move_front(t_core *core)
{
	if (core->map[(int)(core->player.pos.y + core->player.dir.y * MSPEED)]
		[(int)core->player.pos.x] != '1')
			core->player.pos.y += core->player.dir.y * MSPEED;
	if (core->map[(int)core->player.pos.y]
		[(int)(core->player.pos.x + core->player.dir.x * MSPEED)] != '1')
			core->player.pos.x += core->player.dir.x * MSPEED;
	core->player = rc_start(*core);
	return (core);
}

// Move the player one spet back (if there are no walls)
t_core	*move_back(t_core *core)
{
	if (core->map[(int)(core->player.pos.y - core->player.dir.y * MSPEED)]
		[(int)core->player.pos.x] != '1')
			core->player.pos.y -= core->player.dir.y * MSPEED;
	if (core->map[(int)core->player.pos.y]
		[(int)(core->player.pos.x - core->player.dir.x * MSPEED)] != '1')
			core->player.pos.x -= core->player.dir.x * MSPEED;
	core->player = rc_start(*core);
	return (core);
}

// Move the player one spet to the left (if there are no walls)
t_core	*move_left(t_core *core)
{
	if ((int)core->player.pos.x >= core->mapconf.map_x)
		return (core);
	if (core->map[(int)(core->player.pos.y - core->player.plane.y * MSPEED)]
		[(int)core->player.pos.x] != '1')
			core->player.pos.y -= core->player.plane.y * MSPEED;
	if (core->map[(int)core->player.pos.y]
		[(int)(core->player.pos.x - core->player.plane.x * MSPEED)] != '1')
			core->player.pos.x -= core->player.plane.x * MSPEED;
	core->player = rc_start(*core);
	return (core);
}

// Move the player one spet to the right (if there are no walls)
t_core	*move_right(t_core *core)
{
	if ((int)core->player.pos.x >= core->mapconf.map_x)
		return (core);
	if (core->map[(int)(core->player.pos.y + core->player.plane.y * MSPEED)]
		[(int)core->player.pos.x] != '1')
			core->player.pos.y += core->player.plane.y * MSPEED;
	if (core->map[(int)core->player.pos.y]
		[(int)(core->player.pos.x + core->player.plane.x * MSPEED)] != '1')
			core->player.pos.x += core->player.plane.x * MSPEED;
	core->player = rc_start(*core);
	return (core);
}

// Rotate playerw
t_core	*rotation(t_core *core, char direction)
{
	double	dirx;
	double	diry;
	double	planex;
	double	planey;

	dirx = core->player.dir.x;
	diry = core->player.dir.y;
	planex = core->player.plane.x;
	planey = core->player.plane.y;
	if (direction == 'L')
	{
		core->player.dir.x = dirx * cos(-RSPEED) - diry * sin(-RSPEED);
		core->player.dir.y = dirx * sin(-RSPEED) + diry * cos(-RSPEED);
		core->player.plane.x = planex * cos(-RSPEED) - planey * sin(-RSPEED);
		core->player.plane.y = planex * sin(-RSPEED) + planey * cos(-RSPEED);
	}
	if (direction == 'R')
	{
		core->player.dir.x = dirx * cos(RSPEED) - diry * sin(RSPEED);
		core->player.dir.y = dirx * sin(RSPEED) + diry * cos(RSPEED);
		core->player.plane.x = planex * cos(RSPEED) - planey * sin(RSPEED);
		core->player.plane.y = planex * sin(RSPEED) + planey * cos(RSPEED);
	}
	core->player = rc_start(*core);
	return (core);
}
