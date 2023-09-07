/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:48:16 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/07 13:48:59 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
