/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapconf_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:44:09 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/19 20:17:58 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cb_free_mc(t_mapconf *mapconf, char **file)
{
	(void)file;
	ft_putstr_fd("Error\nDuplicate params\n", 2);
	if (mapconf->e_file)
		free(mapconf->e_file);
	if (mapconf->w_file)
		free(mapconf->w_file);
	if (mapconf->n_file)
		free(mapconf->n_file);
	if (mapconf->s_file)
		free(mapconf->s_file);
	exit (1);
}

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
