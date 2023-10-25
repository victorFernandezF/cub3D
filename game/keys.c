/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:17:40 by victofer          #+#    #+#             */
/*   Updated: 2023/10/25 16:15:07 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Checks if the movement speed is bigger than 2 (that could
// produce some errors in execution). If so, print an error message.
void	check_max_speed(void)
{
	if (MSPEED >= 2)
	{
		ft_putstr_fd("\nError\nMovement speed is too hight.\n", 2);
		ft_putstr_fd(" * Must be < 2\n\n", 2);
		exit(-1);
	}
}

// Evaluate the pressed key and call to de correct function.
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
	return (0);
}
