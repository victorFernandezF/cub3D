/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:57:38 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/08 14:47:56 by fortega-         ###   ########.fr       */
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

char	*cb_tmpcolor(char *str)
{
	char	*tmp;
	int		i;

	printf("tmpcolor: %s\n", str);
	tmp = (char *)malloc(5 * sizeof(char));
	i = 0;
	if (!cb_isnum(str[i]))
	{
		tmp[0] = '-';
		tmp[1] = '1';
		tmp[2] = '\0';
		return (tmp);
	}
	while ((str[i] && cb_isnum(str[i])) && i < 5)
	{
		printf("c: %c --- i: %d\n", str[i], i);
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	printf("tmp: %s\n", tmp);
	return (tmp);
}

char	**cb_colormat(char *str)
{
	char	**mat;
	int		i;
	int		j;

	mat = (char **)malloc(4 * sizeof(char *));
	i = 0;
	j = 0;
	while (cb_isspace(str[i]))
		i++;
	if (cb_isnum(str[i]))
		mat[j++] = cb_tmpcolor(&str[i]);
	while (str[i++] != ',')
		i++;
	while (cb_isspace(str[i]))
		i++;
	if (cb_isnum(str[i]))
		mat[j++] = cb_tmpcolor(&str[i]);
	while (str[i++] != ',')
		i++;
	while (cb_isspace(str[i]))
		i++;
	if (cb_isnum(str[i]))
		mat[j++] = cb_tmpcolor(&str[i]);
	mat[j] = NULL;
	printmat(mat);
	printf("\n");
	return (mat);
}

int	cb_makecolor(char *str)
{
	char	**cmat;
	int		r;
	int		g;
	int		b;
	int		i;

	cmat = cb_colormat(str);
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

void	cb_getcolors(t_mapconf *mapconf, char *line)
{
	int	i;

	i = 0;
	printf("ptr map: %p\n", mapconf);
	printf("Entra: %s\n", line);
	while (cb_isspace(line[i]))
		i++;
	if (line[i] == 'F' && cb_isspace(line[i + 1]))
		//printf("f_color\n");
		mapconf->f_color = cb_makecolor(&line[i + 1]);
	if (line[i] == 'C' && cb_isspace(line[i + 1]))
		//printf("c_color\n");
		mapconf->c_color = cb_makecolor(&line[i + 1]);
}
