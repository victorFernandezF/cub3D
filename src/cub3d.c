/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:03:35 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/19 16:08:36 by fortega-         ###   ########.fr       */
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
	mlx_destroy_window(core.mlx, core.win);
	cb_freecore(&core);
}
