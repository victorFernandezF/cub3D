/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:03:35 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/12 10:57:04 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	printmat(core.file);
	cb_printmc(&(core.mapconf));
	//printf("MAP: \n");
	//printmat(core.map);
	cb_freecore(&core);
}
