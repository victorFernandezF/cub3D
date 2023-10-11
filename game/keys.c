/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:17:40 by victofer          #+#    #+#             */
/*   Updated: 2023/10/11 10:49:58 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		core = rotation(core, 'L');
	if (key == K_R_ARROW)
		core = rotation(core, 'R');
	//printcore(*core);
	//print_player_stuff(&core->player);
	return (0);
}

