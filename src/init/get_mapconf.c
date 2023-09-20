/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapconf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:57:35 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/20 08:53:57 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_mapconf	cb_init_mc(void);
void		cb_fill_text(t_mapconf *mapconf, char t, char *str, char **mfile);

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

void	cb_fill_text(t_mapconf *mapconf, char t, char *str, char **mfile)
{
	if (t == 'N' && mapconf->n_file == NULL)
		mapconf->n_file = cb_routefile(str);
	else if (t == 'S' && mapconf->s_file == NULL)
		mapconf->s_file = cb_routefile(str);
	else if (t == 'W' && mapconf->w_file == NULL)
		mapconf->w_file = cb_routefile(str);
	else if (t == 'E' && mapconf->e_file == NULL)
		mapconf->e_file = cb_routefile(str);
	else
		cb_free_mc(mapconf, mfile);
}

void	cb_gettext(t_mapconf *mapconf, char *line, char **file)
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
			cb_fill_text(mapconf, 'N', &line[i + 2], file);
		if (line[i] == 'S' && line[i + 1] == 'O' && cb_isspace(line[i + 2]))
			cb_fill_text(mapconf, 'S', &line[i + 2], file);
		if (line[i] == 'E' && line[i + 1] == 'A' && cb_isspace(line[i + 2]))
			cb_fill_text(mapconf, 'E', &line[i + 2], file);
		if (line[i] == 'W' && line[i + 1] == 'E' && cb_isspace(line[i + 2]))
			cb_fill_text(mapconf, 'W', &line[i + 2], file);
		i++;
	}
}

unsigned char	cb_isparam(char *line)
{
	int	i;

	i = 0;
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

	mapconf = cb_init_mc();
	i = 0;
	while (file[i] && i < 6)
	{
		type = cb_isparam(file[i]);
		if (type)
		{
			if (type == 1)
				cb_gettext(&mapconf, file[i], file);
			if (type == 2)
				cb_getcolors(&mapconf, file[i], file);
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
