/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:20:40 by victofer          #+#    #+#             */
/*   Updated: 2023/10/09 18:20:47 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_core	*move_front(t_core *core)
{
	if (core->player.pos.y <= 0)
		return (core);
	if (core->map[(int)(core->player.pos.y + core->player.dir.y * MSPEED)]
		[(int)core->player.pos.x] != '1')
			core->player.pos.y += core->player.dir.y * MSPEED;
	if (core->map[(int)core->player.pos.y]
		[(int)(core->player.pos.x + core->player.dir.x * MSPEED)] != '1')
			core->player.pos.x += core->player.dir.x * MSPEED;
	if (core->player.pos.y <= 0)
		return (core);
	core->player = rc_start(*core);
	return (core);
}

t_core	*move_back(t_core *core)
{
	if (core->player.pos.y == core->mapconf.map_y)
		return (core);
	if (core->map[(int)(core->player.pos.y - core->player.dir.y * MSPEED)]
		[(int)core->player.pos.x] != '1')
			core->player.pos.y -= core->player.dir.y * MSPEED;
	if (core->map[(int)core->player.pos.y]
		[(int)(core->player.pos.x - core->player.dir.x * MSPEED)] != '1')
			core->player.pos.x -= core->player.dir.x * MSPEED;
	if (core->player.pos.y == core->mapconf.map_y)
		return (core);
	core->player = rc_start(*core);
	return (core);
}

t_core	*move_left(t_core *core)
{
	if ((int)core->player.pos.x == 0)
		return (core);
	if (core->map[(int)(core->player.pos.y - core->player.plane.y * MSPEED)]
		[(int)core->player.pos.x] != '1')
			core->player.pos.y -= core->player.plane.y * MSPEED;
	if (core->map[(int)core->player.pos.y]
		[(int)(core->player.pos.x - core->player.plane.x * MSPEED)] != '1')
			core->player.pos.x -= core->player.plane.x * MSPEED;
	if ((int)core->player.pos.x == 0)
		return (core);
	core->player = rc_start(*core);
	return (core);
}

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
	if ((int)core->player.pos.x >= core->mapconf.map_x)
		return (core);
	core->player = rc_start(*core);
	return (core);
}
