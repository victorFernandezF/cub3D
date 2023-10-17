/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:50:58 by fortega-          #+#    #+#             */
/*   Updated: 2023/10/17 08:39:08 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	cb_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

bool	cb_isspace(char c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (true);
	else
		return (false);
}

bool	cb_emptyln(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\n')
		return (true);
	while (str[i])
	{
		if (!cb_isspace(str[i]) && str[i] != '\n')
			return (false);
		if (str[i] == '\n')
			return (true);
		i++;
	}
	return (true);
}

int	cb_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
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
