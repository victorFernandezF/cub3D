/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:08:08 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/18 15:47:41 by fortega-         ###   ########.fr       */
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
	if (!cb_closecheck(core))
	{
		ft_putstr_fd("Map error, exiting\n", 2);
		cb_freecore(core);
		exit (1);
	}
}

t_core	cb_init(char **argv)
{
	t_core	core;

	core.file = NULL;
	core.map = NULL;
	core.mapconf.e_file = NULL;
	core.mapconf.w_file = NULL;
	core.mapconf.n_file = NULL;
	core.mapconf.s_file = NULL;
	core.file = cb_getfile(argv[1]);
	if (!core.file[0])
	{
		ft_putstr_fd("Error\nEmpty file, exiting\n", 2);
		exit (1);
	}
	cb_divfile(&core);
	return (core);
}
