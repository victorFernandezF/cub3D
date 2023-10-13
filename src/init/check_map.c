/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:21:47 by fortega-          #+#    #+#             */
/*   Updated: 2023/10/13 10:04:11 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	cb_charsallow_play(char c);
bool	cb_charsallow_map(char c);
bool	cb_failchar(char c);
bool	cb_check_players(int p);
void	cb_ff(char **tab, t_point size, t_point begin, int	*f);

t_point	cb_get_begin(char **map)
{
	t_point	begin;
	int		x;
	int		y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'W' || map[y][x] == 'E')
			{
				begin.x = x;
				begin.y = y;
				return (begin);
			}
		}
	}
	begin.x = -2;
	begin.y = -2;
	return (begin);
}

bool	cb_closecheck(t_core *core)
{
	int		f;
	t_point	size;
	t_point	begin;
	char	**tmp;

	f = 0;
	tmp = cb_getmap_fill(core->file);
	size.x = core->mapconf.map_x;
	size.y = core->mapconf.map_y;
	begin = cb_get_begin(tmp);
	cb_ff(tmp, size, begin, &f);
	if ((f != 0) || ((begin.x == 0 || begin.x == size.x)
			|| (begin.y == 0 || begin.y == size.y)))
	{
		ft_putstr_fd("Error:\nMap not closed\n", 2);
		cb_freemat(tmp);
		return (false);
	}
	else
	{
		cb_freemat(tmp);
		return (true);
	}
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

bool	cb_map_elines(char **map)
{
	int	y;

	y = 0;
	while (map[y][0] == '*')
		y++;
	while (map[y])
	{
		if (map[y][0] == '*')
		{
			ft_putstr_fd("Empty lines on map\n", 2);
			return (true);
		}
		y++;
	}
	return (false);
}
