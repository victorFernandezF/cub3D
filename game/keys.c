/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:17:40 by victofer          #+#    #+#             */
/*   Updated: 2023/10/06 11:10:07 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_core	*move_front(t_core *core, double old_x, double old_y)
{
	//double	x;
	//double	y;

	(void)old_y;
	(void)old_x;
	if (core->map[(int)(core->player.pos.x + core->player.dir.x * MSPEED)]
		[(int)core->player.pos.y] != '1')
			core->player.pos.x += core->player.dir.x * MSPEED;
	if (core->map[(int)core->player.pos.x]
		[(int)(core->player.pos.y + core->player.dir.y * MSPEED)] != '1')
			core->player.pos.y += core->player.dir.y * MSPEED;
	
	/* x = core->player.grid_coord.x + old_x * MSPEED;
	y = core->player.grid_coord.y + old_y * MSPEED;

	if (core->map[(int)core->player.pos.y][(int)(x + core->player.dir.x)] != '1')
		core->player.pos.x = x;
	if (core->map[(int)(y + core->player.dir.y)][(int)core->player.pos.y] != '1')	
		core->player.pos.y= y;
  	
	if (core->map[(int)core->player.grid_coord.y - 1]
		[(int)core->player.grid_coord.x] == '1')
			return (core);		
	core->map[(int)y][(int)x] = core->player.player;
	
	core->map[(int)core->player.grid_coord.y]
		[(int)core->player.grid_coord.x] = '0';	 */
	return (core);
}

t_core	*move_back(t_core *core, double old_x, double old_y)
{
	double	x;
	double	y;

	x = core->player.grid_coord.x + old_x * MSPEED;
	y = core->player.grid_coord.y + old_y * MSPEED;

	if (core->map[(int)core->player.pos.y][(int)(x + core->player.dir.x)] != '1')
		core->player.pos.x = x;
	if (core->map[(int)(y + core->player.dir.y)][(int)core->player.pos.y] != '1')	
		core->player.pos.y= y;
	if (core->map[(int)core->player.grid_coord.y + 1]
		[(int)core->player.grid_coord.x] == '1')
			return (core);		
	core->map[(int)y][(int)x] = core->player.player;
	
	core->map[(int)core->player.grid_coord.y]
		[(int)core->player.grid_coord.x] = '0';	
  	printf("TEST \n");
	return (core);
}

int	input(int key, t_core *core)
{
	t_player	*pl;

	pl = &core->player;
	if (key == K_ESC)
		cb_exit(core);
	if (key == K_W)
	{
		core = move_front(core, pl->dir.x, pl->dir.y);
		
	}
	if (key == K_S)
	{
		core = move_back(core, pl->dir.x, -pl->dir.y);

	}
	//if (key == K_A)
		//core = move_character(core, pl->plane.x, pl->plane.y);
	//if (key == K_D)
		//core = move_character(core, -pl->plane.x, pl->plane.y);
	core->player = rc_start(*core);
	printmat(core->map);
	printf("\n");
	return (0);
}
