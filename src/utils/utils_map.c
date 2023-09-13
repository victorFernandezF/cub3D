/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:58:54 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/13 14:16:41 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	cb_charsallow_play(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

bool	cb_charsallow_map(char c)
{
	if (c == '1' || c == '0' || c == ' ')
		return (true);
	return (false);
}

int	cb_maxx(char **file)
{
	int	i;
	int	j;
	int	m;

	i = 6;
	m = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j])
			j++;
		if (j > m)
			m = j;
		i++;
	}
	return (m);
}

char	*cb_fillrows_full(char *s, int size)
{
	char	*tmp;
	int		i;

	tmp = (char *) malloc((size + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		tmp[i] = s[i];
		i++;
	}
	while (i < size)
	{
		tmp[i] = '*';
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int	cb_size_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
