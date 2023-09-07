/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:50:58 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/07 16:25:47 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cb_gettext(t_mapconf *mapconf, char *line)
{
	
}

int	cb_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	printmat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		ft_printf("str: %s\n", mat[i]);
		i++;
	}
}