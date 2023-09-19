/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:48:16 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/19 18:45:10 by fortega-         ###   ########.fr       */
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
