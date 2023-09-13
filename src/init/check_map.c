/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:21:47 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/13 18:29:12 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	cb_charsallow_play(char c);
bool	cb_charsallow_map(char c);
bool	cb_failchar(char c);
bool	cb_check_players(int p);

t_point	*cb_get_begin(char **map)
{
	t_point	*begin;
	int		x;
	int		y;

	begin = (t_point *)malloc(sizeof(t_point));
	x = -1;
	y = -1;
	while (map[++y])
	{
		while (map[y][++x])
		{
			if (map[y][x] == '1')
			{
				begin->x = x;
				begin->y = y;
				return (begin);
			}
		}
	}
	begin->x = -2;
	begin->y = -2;
	return (begin);
}

void	cb_closecheck(t_core *core)
{
	//int		p;
	t_point	size;
	t_point	*begin;
	char	**tmp;

	tmp = cb_getmap_fill(core->file);
	size.x = core->mapconf.map_x;
	size.y = core->mapconf.map_y;
	begin = cb_get_begin(tmp);
	printf("y: %d, x: %d\n", begin->y, begin->x);
	cb_freemat(tmp);
	free(begin);
	/*p = core->prizes;
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
	}*/
}

bool	cb_chars_map(char **map)
{
	int	x;
	int	y;
	int	player;

	y = 5;
	player = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (cb_charsallow_map(map[y][x]) || cb_charsallow_play(map[y][x]))
			{
				if (cb_charsallow_play(map[y][x]))
					player++;
			}
			else
				return (cb_failchar(map[y][x]));
		}
	}
	return (cb_check_players(player));
}

bool	cb_check_map(char **file)
{
	char	**tmp;
	bool	val;

	tmp = cb_getmap(file);
	val = cb_chars_map(tmp);
	free(tmp);
	return (val);
}
