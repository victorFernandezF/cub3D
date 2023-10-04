/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:17:40 by victofer          #+#    #+#             */
/*   Updated: 2023/10/04 13:54:56 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	input(int key, t_core *core)
{
	t_player	*pl;

	pl = &core->player;
	if (key == 53)
		cb_exit(core);
	if (key == 13)
	{
		
		if (core->map[(int)pl->pos.x][(int)pl->pos.y + 1] != '1')
			pl->pos.y += 1;
		printf("(%i, %i)\n", (int)pl->pos.x, (int)pl->pos.y);
		printf("%c\n", core->map[(int)pl->pos.x + 1][(int)pl->pos.y]);
		printf("%c\n", core->map[(int)pl->pos.x + 1][(int)pl->pos.y]);
 		/*printf("%c\n", core->map[(int)(pl->pos.x + pl->direction.y * MSPEED)][(int)pl->pos.y]);
		if (core->map[(int)(pl->pos.x + pl->direction.x * MSPEED)]
			[(int)pl->pos.y] != '1')
			pl->pos.x += pl->direction.x * 1;
		if (core->map[(int)pl->pos.x]
			[(int)(pl->pos.y + pl->direction.y * MSPEED)] != '1')
			pl->pos.y += pl->direction.y * MSPEED; */
	}
	core->player = *pl;
	rc_start(*core);
	return (0);
}
