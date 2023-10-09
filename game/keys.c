/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:17:40 by victofer          #+#    #+#             */
/*   Updated: 2023/10/09 19:04:58 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_core	*rotation_left(t_core *core)
{
	double	dirx;
	double	diry;
	double	planex;
	double	planey;

	printf("TEST\n");
	dirx = core->player.dir.x;
	diry = core->player.dir.y;
	core->player.dir.x = dirx * cos(-RSPEED) - diry * sin(-RSPEED);
	core->player.dir.y = dirx * sin(-RSPEED) + diry * cos(-RSPEED);
	planex = core->player.plane.x;
	planey = core->player.plane.y;
	core->player.plane.x = planex * cos(-RSPEED) - planey * sin(-RSPEED);
	core->player.plane.y = planex * sin(-RSPEED) + planey * cos(-RSPEED);
	core->player = rc_start(*core);
	return (core);
}

t_core	*rotation_right(t_core *core)
{
	double	dirx;
	double	diry;
	double	planex;
	double	planey;

	dirx = core->player.dir.x;
	diry = core->player.dir.y;
	core->player.dir.x = dirx * cos(RSPEED) - diry * sin(RSPEED);
	core->player.dir.y = dirx * sin(RSPEED) + diry * cos(RSPEED);
	planex = core->player.plane.x;
	planey = core->player.plane.y;
	core->player.plane.x = planex * cos(RSPEED) - planey * sin(RSPEED);
	core->player.plane.y = planex * sin(RSPEED) + planey * cos(RSPEED);
	core->player = rc_start(*core);
	return (core);
}

int	input(int key, t_core *core)
{
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
	if (key == K_L_ARROW)
		core = rotation_left(core);
	if (key == K_R_ARROW)
		core = rotation_right(core);
	return (0);
}

