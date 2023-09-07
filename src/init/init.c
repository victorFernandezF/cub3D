/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:08:08 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/07 16:25:00 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_mapconf	cb_getmapconf(char **file)
{
	t_mapconf	mapconf;
	int			i;

	i = 0;
	while (file[i] && i < 6)
	{
		if (file[i][0] == 'F' || file[i][0] == 'C')
			cb_getcolors(&mapconf, file[i]);
		else
			cb_gettext(&mapconf, file[i]);
		i++;
	}
}

void	cb_divfile(t_core *core)
{
	core->mapconf = cb_getmapconf(core->file);
}

t_core	cb_init(char **argv)
{
	t_core	core;

	core.file = cb_getfile(argv[1]);
	cb_divfile(&core);
	return (core);
}
