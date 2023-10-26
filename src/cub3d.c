/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:03:35 by fortega-          #+#    #+#             */
/*   Updated: 2023/10/26 17:58:41 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_leaks(void);

int	cb_exit(t_core *core)
{
	cb_freecore(core);
	exit (0);
	return (0);
}

int	cb_input(int key, t_core *core)
{
	if (key == 53)
		cb_exit(core);
	return (0);
}

int	main(int argc, char **argv)
{
	t_core	core;

	if (argc != 2 || (argc == 2 && !argv[1]))
	{
		printf("Error\nNeeded .cub map\n");
		return (0);
	}
	atexit(ft_leaks);
	check_max_speed();
	core = cb_init(argv);
	core.player = init_player_datas(core);
	mlx_hook(core.win, 17, 0, cb_exit, &core);
	mlx_hook(core.win, 2, 0, input, &core);
	core.player = rc_start(core);
	mlx_loop(core.mlx);
	cb_freecore(&core);
	return (0);
}
