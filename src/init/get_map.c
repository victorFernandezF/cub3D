/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:44:54 by fortega-          #+#    #+#             */
/*   Updated: 2023/10/24 09:03:53 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**cb_getmap_fill(char **file)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (file[i])
		i++;
	while (cb_emptyln(file[++j]))
		i--;
	map = (char **)malloc((i - 5) * sizeof(char *));
	i = 6;
	j = 0;
	while (cb_emptyln(file[i]))
		i++;
	while (file[i])
	{
		map[j] = cb_fillrows_full(file[i], cb_maxx(file));
		i++;
		j++;
	}
	map[j] = NULL;
	return (map);
}

int	cb_size_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	cb_size_x(char **map)
{
	int	i;
	int	j;
	int	m;

	i = 0;
	m = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > m)
			m = j;
		i++;
	}
	return (m);
}

/*char	**cb_getmap(char **file)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	while (file[i])
		i++;
	map = (char **)malloc((i - 5) * sizeof(char *));
	i = 6;
	j = 0;
	while (file[i])
	{
		map[j] = cb_fillrows(file[i]);
		i++;
		j++;
	}
	map[j] = NULL;
	return (map);
}*/
