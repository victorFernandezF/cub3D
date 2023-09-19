/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:58:22 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/19 11:14:50 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cb_xpm_error(t_core *core, char *xpm)
{
	ft_putstr_fd("Error\nFile xpm <", 2);
	ft_putstr_fd(xpm, 2);
	ft_putstr_fd("> not compatible\n", 2);
	cb_freecore(core);
	exit (1);
}

void	cb_check_xpm(t_core *core)
{
	core->imgs.n = mlx_xpm_file_to_image(core->mlx, core->mapconf.n_file,
			&core->imgs.size_x, &core->imgs.size_y);
	if (!core->imgs.n)
		cb_xpm_error(core, core->mapconf.n_file);
	core->imgs.s = mlx_xpm_file_to_image(core->mlx, core->mapconf.s_file,
			&core->imgs.size_x, &core->imgs.size_y);
	if (!core->imgs.s)
		cb_xpm_error(core, core->mapconf.s_file);
	core->imgs.w = mlx_xpm_file_to_image(core->mlx, core->mapconf.w_file,
			&core->imgs.size_x, &core->imgs.size_y);
	if (!core->imgs.w)
		cb_xpm_error(core, core->mapconf.w_file);
	core->imgs.e = mlx_xpm_file_to_image(core->mlx, core->mapconf.e_file,
			&core->imgs.size_x, &core->imgs.size_y);
	if (!core->imgs.e)
		cb_xpm_error(core, core->mapconf.e_file);
}
