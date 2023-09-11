/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:50:58 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/11 12:24:02 by fortega-         ###   ########.fr       */
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
	if (mapconf->c_color)
		printf("%d -> %X\n", mapconf->c_color, mapconf->c_color);
	if (mapconf->f_color)
		printf("%d -> %X\n", mapconf->f_color, mapconf->f_color);
	if (mapconf->n_file)
		printf("<%s>\n", mapconf->n_file);
	if (mapconf->s_file)
		printf("<%s>\n", mapconf->s_file);
	if (mapconf->e_file)
		printf("<%s>\n", mapconf->e_file);
	if (mapconf->w_file)
		printf("<%s>\n", mapconf->w_file);
}
