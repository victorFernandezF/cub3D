/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:38:18 by fortega-          #+#    #+#             */
/*   Updated: 2023/10/19 13:24:13 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	printmat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		ft_printf("str: <%s>\n", mat[i]);
		i++;
	}
}

void	cb_printmc(t_mapconf *mapconf)
{
	printf("\n\n");
	printf("C color: %d -> %X\n", mapconf->c_color, mapconf->c_color);
	printf("F color: %d -> %X\n\n", mapconf->f_color, mapconf->f_color);
	if (mapconf->n_file)
		printf("N file: <%s>\n", mapconf->n_file);
	if (mapconf->s_file)
		printf("S file: <%s>\n", mapconf->s_file);
	if (mapconf->e_file)
		printf("E file: <%s>\n", mapconf->e_file);
	if (mapconf->w_file)
		printf("W file: <%s>\n\n", mapconf->w_file);
	printf("Map X size: %d\n", mapconf->map_x);
	printf("Map Y size: %d\n", mapconf->map_y);
}