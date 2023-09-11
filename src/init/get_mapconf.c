/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapconf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:57:35 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/11 12:17:58 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*cb_routefile(char *str)
{
	char	*route;
	int		i;
	int		j;

	i = 0;
	while (cb_isspace(str[i]))
		i++;
	if (str[i] == '\0' || str[i] == '\n')
		return (NULL);
	route = (char *)malloc((cb_strlen(&str[i]) + 1) * sizeof(char));
	if (!route)
		return (NULL);
	j = 0;
	while (str[i] && str[i] != '\n' && str[i] != ' ')
	{
		route[j] = str[i];
		i++;
		j++;
	}
	route[j] = '\0';
	return (route);
}

void	cb_gettext(t_mapconf *mapconf, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (cb_isspace(line[i]))
		{
			i++;
			continue ;
		}
		if (line[i] == 'N' && line[i + 1] == 'O' && cb_isspace(line[i + 2]))
			mapconf->n_file = cb_routefile(&line[i + 2]);
		if (line[i] == 'S' && line[i + 1] == 'O' && cb_isspace(line[i + 2]))
			mapconf->s_file = cb_routefile(&line[i + 2]);
		if (line[i] == 'E' && line[i + 1] == 'A' && cb_isspace(line[i + 2]))
			mapconf->e_file = cb_routefile(&line[i + 2]);
		if (line[i] == 'W' && line[i + 1] == 'E' && cb_isspace(line[i + 2]))
			mapconf->w_file = cb_routefile(&line[i + 2]);
		i++;
	}
}

unsigned char	cb_isparam(char *line)
{
	int	i;

	i = 0;
	printf("line: %s\n", line);
	while (line[i])
	{
		while (cb_isspace(line[i]))
			i++;
		if ((line[i] == 'F' && cb_isspace(line[i + 1]))
			|| (line[i] == 'C' && cb_isspace(line[i + 1])))
			return (2);
		if ((line[i] == 'N' && line[i + 1] == 'O' && cb_isspace(line[i + 2]))
			|| (line[i] == 'S' && line[i + 1] == 'O' && cb_isspace(line[i + 2]))
			|| (line[i] == 'E' && line[i + 1] == 'A' && cb_isspace(line[i + 2]))
			|| (line[i] == 'W' && line[i + 1] == 'E'
				&& cb_isspace(line[i + 2])))
			return (1);
		else
			return (0);
		i++;
	}
	return (0);
}

t_mapconf	cb_getmapconf(char **file)
{
	t_mapconf	mapconf;
	int			i;
	char		type;

	i = 0;
	while (file[i] && i < 6)
	{
		type = cb_isparam(file[i]);
		if (type)
		{
			if (type == 1)
				cb_gettext(&mapconf, file[i]);
			if (type == 2)
				cb_getcolors(&mapconf, file[i]);
		}
		else
		{
			cb_freemat(file);
			cb_fail("Wrong map params\n");
		}
		i++;
	}
	return (mapconf);
}
