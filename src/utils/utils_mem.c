/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:48:16 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/19 16:11:04 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cb_freecore(t_core *core)
{
	if (core->file)
		cb_freemat(core->file);
	if (core->map)
		cb_freemat(core->map);
	if (core->mapconf.e_file)
		free(core->mapconf.e_file);
	if (core->mapconf.w_file)
		free(core->mapconf.w_file);
	if (core->mapconf.n_file)
		free(core->mapconf.n_file);
	if (core->mapconf.s_file)
		free(core->mapconf.s_file);
	if (core->imgs.n)
		mlx_destroy_image(core->mlx, core->imgs.n);
		//free(core->imgs.n);
	if (core->imgs.s)
		mlx_destroy_image(core->mlx, core->imgs.s);
		//free(core->imgs.s);
	if (core->imgs.w)
		mlx_destroy_image(core->mlx, core->imgs.w);
		//free(core->imgs.w);
	if (core->imgs.e)
		mlx_destroy_image(core->mlx, core->imgs.e);
		//free(core->imgs.e);
}

void	cb_freemat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free (mat[i]);
	free (mat);
}

void	cb_freemat_rev(char **mat, int i)
{
	while (i > 0)
	{
		free(mat[i]);
		i--;
	}
	free (mat[i]);
	free (mat);
}
