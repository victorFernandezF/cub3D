/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:08:08 by fortega-          #+#    #+#             */
/*   Updated: 2023/10/10 08:48:44 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	cb_size_y(char **map);

void	cb_divfile(t_core *core)
{
	core->mapconf = cb_getmapconf(core->file);
	if (!cb_check_params(core))
	{
		ft_putstr_fd("Params error, exiting\n", 2);
		cb_freecore(core);
		exit (1);
	}
	if (!cb_chars_map(core->file))
	{
		ft_putstr_fd("Map error, exiting\n", 2);
		cb_freecore(core);
		exit (1);
	}
	core->map = cb_getmap_fill(core->file);
	core->mapconf.map_y = cb_size_y(core->map);
	core->mapconf.map_x = cb_maxx(core->map);
	if (cb_map_elines(core->map) || !cb_closecheck(core))
	{
		ft_putstr_fd("Map error, exiting\n", 2);
		cb_freecore(core);
		exit (1);
	}
}

t_img	cb_init_img(void)
{
	t_img	imgs;

	imgs.size_x = IMGS_X;
	imgs.size_y = IMGS_Y;
	imgs.n = NULL;
	imgs.s = NULL;
	imgs.w = NULL;
	imgs.e = NULL;
	return (imgs);
}

t_mapconf	cb_init_mc(void)
{
	t_mapconf	mapconf;

	mapconf.e_file = NULL;
	mapconf.w_file = NULL;
	mapconf.n_file = NULL;
	mapconf.s_file = NULL;
	mapconf.f_color = -2;
	mapconf.c_color = -2;
	mapconf.map_x = -1;
	mapconf.map_y = -1;
	return (mapconf);
}

void	cb_init_mlx(t_core *core)
{
	core->mlx = mlx_init();
	core->win = mlx_new_window(core->mlx, DWIN_X, DWIN_Y, "Cub3D");
}

t_core	cb_init(char **argv)
{
	t_core	core;

	core.win_x = 0;
	core.win_y = 0;
	core.file = NULL;
	core.map = NULL;
	core.imgs = cb_init_img();
	core.mlx = NULL;
	core.win = NULL;
	core.file = cb_getfile(argv[1]);
	if (!core.file[0])
	{
		ft_putstr_fd("Error\nEmpty file, exiting\n", 2);
		exit (1);
	}
	cb_divfile(&core);
	cb_init_mlx(&core);
	cb_check_xpm(&core);
	return (core);
}
