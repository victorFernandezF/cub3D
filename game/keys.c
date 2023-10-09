/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:17:40 by victofer          #+#    #+#             */
/*   Updated: 2023/10/09 12:28:41 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_core	*move_front(t_core *core)
{
	printf("posX: %f %i\n", core->player.pos.y, (int)core->player.pos.y);
	printf("(%i, %i)\n", (int)(core->player.pos.x + core->player.dir.x * MSPEED),
		(int)core->player.pos.y);
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
	return (core);
}

int	input(int key, t_core *core)
{
	///t_player	*pl;

	//pl = &core->player;
	//core->player.po
	if (key == K_ESC)
		cb_exit(core);
	if (key == K_W)
		core = move_front(core);
	if (key == K_S)
		core = move_back(core);
	if (key == K_A)
		core = move_left(core);
	if (key == K_D)
		core = move_right(core);
	print_player_stuff(&core->player);
	printf("%sCoords: (%f, %f)%s\n", Y, core->player.pos.x, core->player.pos.y, W);
	core->player = rc_start(*core);
	return (0);
}
