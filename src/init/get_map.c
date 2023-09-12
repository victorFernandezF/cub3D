/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:44:54 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/12 10:53:47 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	printf("%p\n", map);
	return (0);
}

int	cb_maxx(char **file)
{
	int	i;
	int	j;
	int	m;

	i = 0;
	m = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j])
			j++;
		printf("j: %d\n", j);
		if (j > m)
			m = j;
		i++;
	}
	printf("maxx: %d\n", m);
	return (m);
}
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
	int		k;

	i = 0;
	while (file[i])
		i++;
	map = (char **)malloc((i - 5) * sizeof(char *));
	i = 6;
	j = 0;
	while (file[i])
	{
		k = -1;
		map[j] = (char *)malloc((cb_maxx(file) + 1) * sizeof(char));
		while (file[i][++k])
			map[j][k] = file[i][k];
		while (k <= cb_maxx(file))
			map[j][k++] = '*';
		map[j][k] = '\0';
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
	int		k;

	i = 0;
	while (file[i])
		i++;
	map = (char **)malloc((i - 5) * sizeof(char *));
	i = 6;
	j = 0;
	while (file[i])
	{
		k = -1;
		map[j] = (char *)malloc((ft_strlen(file[i] + 1) * sizeof(char)));
		while (file[i][++k])
			map[j][k] = file[i][k];
		map[j][k] = '\0';
		i++;
		j++;
	}
	map[j] = NULL;
	return (map);
}
