/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:03:35 by fortega-          #+#    #+#             */
/*   Updated: 2023/10/20 11:17:24 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	printcore(t_core core)
{
	printf("\nFile:\n");
	printmat(core.file);
	cb_printmc(&(core.mapconf));
	printf("\nMAP: \n");
	printmat(core.map);
}

void	ft_leaks(void)
{
	system("leaks -q cub3D");
}

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
	core = cb_init(argv);
	printcore(core);
	core.player = init_player_datas(core);
	print_player_stuff(&core.player);
	mlx_hook(core.win, 17, 0, cb_exit, &core);
	mlx_hook(core.win, 2, 0, input, &core);
	core.player = rc_start(core);
	mlx_loop(core.mlx);
	cb_freecore(&core);
	return (0);
}
