/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:50:58 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/18 11:41:10 by fortega-         ###   ########.fr       */
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

void	printmat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		ft_printf("str: <%s>\n", mat[i]);
		i++;
	}
}

void	cb_printmc(t_mapconf *mapconf)
{
	printf("\n\n");
	printf("C color: %d -> %X\n", mapconf->c_color, mapconf->c_color);
	printf("F color: %d -> %X\n\n", mapconf->f_color, mapconf->f_color);
	if (mapconf->n_file)
		printf("N file: <%s>\n", mapconf->n_file);
	if (mapconf->s_file)
		printf("S file: <%s>\n", mapconf->s_file);
	if (mapconf->e_file)
		printf("E file: <%s>\n", mapconf->e_file);
	if (mapconf->w_file)
		printf("W file: <%s>\n\n", mapconf->w_file);
	printf("Map X size: %d\n", mapconf->map_x);
	printf("Map Y size: %d\n", mapconf->map_y);
}
