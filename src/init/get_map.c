/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:44:54 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/13 13:09:05 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*void	cb_closecheck(t_core *core)
{
	int		p;
	t_point	size;
	t_point	begin;
	char	**tmp;

	tmp = cb_getmap(core->file);
	size.x = core->sx;
	size.y = core->sy;
	begin.x = core->ppx / IMG_SIZE;
	begin.y = core->ppy / IMG_SIZE;
	tmp[begin.y][begin.x] = '0';
	p = core->prizes;
	if (sl_ffc(tmp, size, begin, &p))
	{
		sl_freemat(tmp);
		if (sl_resolve2(core) == 0)
			sl_failfree("Error\nExit not reachable\n", core);
	}
	else
	{
		sl_freemat(tmp);
		sl_failfree("Error\nNot possible take all collectables\n", core);
	}
}*/

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
