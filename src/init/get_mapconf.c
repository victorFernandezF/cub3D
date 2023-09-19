/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapconf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:57:35 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/19 20:27:08 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_mapconf	cb_init_mc(void);
void		cb_fill_text(t_mapconf *mapconf, char t, char *str, char **mfile);

/*char	*cb_fill_text(t_mapconf *mapconf, char *ifile, char *line, char **mfile)
{
	char	*ptr;

	ptr = cb_routefile(line);
	printf("%p - %p\n", mapconf, mfile);
	if (cb_strlen(ifile) == 0)
	{
		printf("retorna\n");
		return (ptr);
	}
	else
	{
		cb_freemat(mfile);
		cb_free_mc(mapconf);
		exit (1);
		printf("nulea\n");
		return (NULL);
	}
}*/

/*void	cb_gettext(t_mapconf *mapconf, char *line, char **file)
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
			mapconf->n_file = cb_fill_text(mapconf,
					mapconf->n_file, &line[i + 2], file);
		if (line[i] == 'S' && line[i + 1] == 'O' && cb_isspace(line[i + 2]))
			mapconf->s_file = cb_fill_text(mapconf,
					mapconf->s_file, &line[i + 2], file);
		if (line[i] == 'E' && line[i + 1] == 'A' && cb_isspace(line[i + 2]))
			mapconf->e_file = cb_fill_text(mapconf,
					mapconf->e_file, &line[i + 2], file);
		if (line[i] == 'W' && line[i + 1] == 'E' && cb_isspace(line[i + 2]))
			mapconf->w_file = cb_fill_text(mapconf,
					mapconf->w_file, &line[i + 2], file);
		i++;
	}
}*/

/*void	cb_gettext(t_mapconf *mapconf, char *line)
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
}*/

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
			//mapconf->n_file = cb_routefile(&line[i + 2]);
		if (line[i] == 'S' && line[i + 1] == 'O' && cb_isspace(line[i + 2]))
			cb_fill_text(mapconf, 'S', &line[i + 2], file);
			//mapconf->s_file = cb_routefile(&line[i + 2]);
		if (line[i] == 'E' && line[i + 1] == 'A' && cb_isspace(line[i + 2]))
			cb_fill_text(mapconf, 'E', &line[i + 2], file);
			//mapconf->e_file = cb_routefile(&line[i + 2]);
		if (line[i] == 'W' && line[i + 1] == 'E' && cb_isspace(line[i + 2]))
			cb_fill_text(mapconf, 'W', &line[i + 2], file);
			//mapconf->w_file = cb_routefile(&line[i + 2]);
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
