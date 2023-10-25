/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:03:34 by fortega-          #+#    #+#             */
/*   Updated: 2023/10/25 08:44:08 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	cb_charsallow_play(char c);
bool	cb_charsallow_map(char c);

bool	cb_is_mapln(char *line)
{
	int	i;

	i = 0;
	if (!line || !line[i] || line[i] == '\n')
		return (false);
	while (line[i])
	{
		if (line[i] == '\n')
			break ;
		if (!cb_charsallow_map(line[i]) && !cb_charsallow_play(line[i])
			&& !cb_isspace(line[i]))
			return (false);
		i++;
	}
	return (true);
}
