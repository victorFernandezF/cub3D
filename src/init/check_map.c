/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:21:47 by fortega-          #+#    #+#             */
/*   Updated: 2023/10/17 13:52:35 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	cb_charsallow_play(char c);
bool	cb_charsallow_map(char c);
bool	cb_failchar(char c);
bool	cb_mapln_cnt(char *line);
int		cb_size_y(char **map);
void	cb_examplefile(void);
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
		ft_putstr_fd("Error\nMap not closed\n", 2);
		cb_freemat(tmp);
		return (false);
	}
	else
	{
		cb_freemat(tmp);
		return (true);
	}
}

bool	cb_check_players(char **map, int p)
{
	if (!cb_check_map(map))
		return (false);
	if (p < 1)
	{
		ft_putstr_fd("Error\nNeeded one player\n", 2);
		return (false);
	}
	if (p > 1)
	{
		ft_putstr_fd("Error\nOnly one player allowed\n", 2);
		return (false);
	}
	return (true);
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
	return (cb_check_players(map, player));
}

bool	cb_check_map(char **map)
{
	int	i;
	int	lns;

	i = 6;
	lns = 0;
	while (map[i])
	{
		if (cb_mapln_cnt(map[i]))
			lns++;
		i++;
	}
	if (lns == 0)
	{
		ft_putstr_fd("Error\nMap needed\n", 2);
		cb_examplefile();
		return (false);
	}
	if (lns < 3 || cb_size_y(map) < 3)
	{
		ft_putstr_fd("Error\nMap minimun 3 lines X 3 rows\n", 2);
		cb_examplefile();
		return (false);
	}
	return (true);
}
