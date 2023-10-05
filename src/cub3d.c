/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:03:35 by fortega-          #+#    #+#             */
/*   Updated: 2023/10/05 18:20:44 by victofer         ###   ########.fr       */
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
	print_player_stuff(core.player);
	core.player.p_img.img_ptr = mlx_new_image(core.mlx, WIDTH, HEIGHT);
	core.player.p_img.data = (int *)mlx_get_data_addr(core.player.p_img.img_ptr,
			&core.player.p_img.bpp, &core.player.p_img.size_l,
			&core.player.p_img.endian);
	//mlx_put_image_to_window(core.mlx, core.win, core.imgs.n, IMGS_X, IMGS_Y);
	mlx_hook(core.win, 17, 0, cb_exit, &core);
	mlx_hook(core.win, 2, 0, input, &core);
	core.player = rc_start(core);
	//cb_exit(&core);
	mlx_loop(core.mlx);
	cb_freecore(&core);
	return (0);
}
