/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:17:40 by victofer          #+#    #+#             */
/*   Updated: 2023/10/19 18:56:26 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	input(int key, t_core *core)
{
	/* char **tmp;
	char old; */
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
	/* tmp = core->map;
	old = tmp[(int)core->player.pos.y][(int)core->player.pos.x];
	tmp[(int)core->player.pos.y][(int)core->player.pos.x] = 'X';
	printf("\n");
	printmap(tmp);
	tmp[(int)core->player.pos.y][(int)core->player.pos.x] = old; */
	return (0);
}
