/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:21:47 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/13 14:54:56 by fortega-         ###   ########.fr       */
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

/*void	cb_closecheck(t_core *core)
{
	int		p;
	t_point	size;
	t_point	begin;
	char	**tmp;

	tmp = cb_getmap_fill(core->file);
	size.x = core->mapconf.map_x;
	size.y = core->mapconf.map_y;
	begin = *(cb_get_begin(tmp));
	tmp[begin.y][begin.x] = 'Z';
	//p = core->prizes;
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

bool	cb_chars_map(char **map)
{
	int	x;
	int	y;
	int	player;

	x = 0;
	y = 0;
	player = 0;
	printf("\n");
	while (map[y])
	{
		while (map[y][x])
		{
			printf("%c", map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	while (map[y])
	{
		while (map[y][x])
		{
			if (cb_charsallow_map(map[y][x]) || cb_charsallow_play(map[y][x]))
			{
				if (cb_charsallow_play(map[y][x]))
					player++;
			}
			else
			{
				printf("line: <%s>\n", map[y]);
				printf("map[%d][%d]\n", y, x);
				return (cb_failchar(map[y][x]));
			}
			x++;
		}
		y++;
	}
	return (cb_check_players(player));
}

bool	cb_check_map(char **map)
{
	return (cb_chars_map(map));
}
