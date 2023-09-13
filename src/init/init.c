/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:08:08 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/13 13:05:03 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cb_divfile(t_core *core)
{
	core->mapconf = cb_getmapconf(core->file);
	if (!cb_check_params(core))
	{
		ft_putstr_fd("Params error, exiting\n", 2);
		cb_freecore(core);
		exit (1);
	}
	//core->map = cb_getmap(core->file);
	core->map = cb_getmap_fill(core->file);
}

t_core	cb_init(char **argv)
{
	t_core	core;

	core.file = cb_getfile(argv[1]);
	cb_divfile(&core);
	return (core);
}
