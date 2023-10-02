/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:57:38 by fortega-          #+#    #+#             */
/*   Updated: 2023/10/02 12:59:03 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	trgb(int t, int r, int g, int b)
{
	if ((r < 0 || r > 255) || (g < 0 || g > 255)
		|| (b < 0 || b > 255))
		return (-1);
	else
		return (t << 24 | r << 16 | g << 8 | b);
}

int	cb_makecolor(char *str)
{
	char	**cmat;
	int		r;
	int		g;
	int		b;
	int		i;

	cmat = cb_split(str, ',');
	r = -1;
	g = -1;
	b = -1;
	i = 0;
	while (cmat[i])
	{
		if (i == 0)
			r = ft_atoi(cmat[i]);
		if (i == 1)
			g = ft_atoi(cmat[i]);
		if (i == 2)
			b = ft_atoi(cmat[i]);
		i++;
	}
	cb_freemat(cmat);
	return (trgb(0, r, g, b));
}

void	cb_getcolors(t_mapconf *mapconf, char *line, char **file)
{
	int	i;

	i = 0;
	while (cb_isspace(line[i]))
		i++;
	if ((line[i] == 'F' && cb_isspace(line[i + 1]))
		&& mapconf->f_color == -2)
		mapconf->f_color = cb_makecolor(&line[i + 1]);
	else if ((line[i] == 'C' && cb_isspace(line[i + 1]))
		&& mapconf->c_color == -2)
		mapconf->c_color = cb_makecolor(&line[i + 1]);
	else
		cb_free_mc(mapconf, file);
}
