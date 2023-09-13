/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:44:54 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/13 13:22:03 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**cb_getmap_fill(char **file)
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
		map[j] = cb_fillrows_full(file[i], cb_maxx(file));
		i++;
		j++;
	}
	map[j] = NULL;
	return (map);
}

char	**cb_getmap(char **file)
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
}
