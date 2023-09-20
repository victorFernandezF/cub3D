/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:48:16 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/20 08:51:03 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cb_free_mc(t_mapconf *mapconf, char **file)
{
	(void)file;
	ft_putstr_fd("Error\nDuplicate params\n", 2);
	if (mapconf->e_file)
		free(mapconf->e_file);
	if (mapconf->w_file)
		free(mapconf->w_file);
	if (mapconf->n_file)
		free(mapconf->n_file);
	if (mapconf->s_file)
		free(mapconf->s_file);
	exit (1);
}

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
