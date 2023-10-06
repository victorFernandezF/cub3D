/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:17:40 by victofer          #+#    #+#             */
/*   Updated: 2023/10/06 11:22:12 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_core	*move_front(t_core *core)
{
	if (core->map[(int)(core->player.pos.x + core->player.dir.x * MSPEED)]
		[(int)core->player.pos.y] != '1')
			core->player.pos.x += core->player.dir.x * MSPEED;
	if (core->map[(int)core->player.pos.x]
		[(int)(core->player.pos.y + core->player.dir.y * MSPEED)] != '1')
			core->player.pos.y += core->player.dir.y * MSPEED;
	return (core);
}

t_core	*move_back(t_core *core)
{
	if (core->map[(int)(core->player.pos.x - core->player.dir.x * MSPEED)]
		[(int)core->player.pos.y] != '1')
			core->player.pos.x -= core->player.dir.x * MSPEED;
	if (core->map[(int)core->player.pos.x]
		[(int)(core->player.pos.y - core->player.dir.y * MSPEED)] != '1')
			core->player.pos.y -= core->player.dir.y * MSPEED;
	return (core);
}
t_core	*move_left(t_core *core)
{
	if (core->map[(int)(core->player.pos.x - core->player.plane.x * MSPEED)]
		[(int)core->player.pos.y] != '1')
			core->player.pos.x -= core->player.plane.x * MSPEED;
	if (core->map[(int)core->player.pos.x]
		[(int)(core->player.pos.y - core->player.plane.y * MSPEED)] != '1')
			core->player.pos.y -= core->player.plane.y * MSPEED;
	return (core);
}

t_core	*move_right(t_core *core)
{
	if (core->map[(int)(core->player.pos.x + core->player.plane.x * MSPEED)]
		[(int)core->player.pos.y] != '1')
			core->player.pos.x += core->player.plane.x * MSPEED;
	if (core->map[(int)core->player.pos.x]
		[(int)(core->player.pos.y + core->player.plane.y * MSPEED)] != '1')
			core->player.pos.y += core->player.plane.y * MSPEED;
	return (core);
}


int	input(int key, t_core *core)
{
	t_player	*pl;

	pl = &core->player;
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
	core->player = rc_start(*core);
	printmat(core->map);
	printf("\n");
	return (0);
}
