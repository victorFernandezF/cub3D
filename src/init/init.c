/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:08:08 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/08 12:55:32 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
