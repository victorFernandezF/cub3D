/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mapconf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:41:16 by fortega-          #+#    #+#             */
/*   Updated: 2023/10/17 13:36:45 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

unsigned char	cb_isparam(char *line);
bool			cb_is_mapln(char *line);
void			cb_examplefile(void);

void	cb_param_miss(t_mapconf mapconf)
{
	if (!mapconf.e_file)
		ft_putstr_fd("Error\nTexture EA not exist\n", 2);
	if (!mapconf.w_file)
		ft_putstr_fd("Error\nTexture WE not exist\n", 2);
	if (!mapconf.n_file)
		ft_putstr_fd("Error\nTexture NO not exist\n", 2);
	if (!mapconf.s_file)
		ft_putstr_fd("Error\nTexture SO not exist\n", 2);
	if (mapconf.c_color == -2)
		ft_putstr_fd("Error\nColor C not exist\n", 2);
	if (mapconf.f_color == -2)
		ft_putstr_fd("Error\nColor F not exist\n", 2);
	cb_examplefile();
}

void	cb_param_fail(char *line)
{
	if (!cb_is_mapln(line))
	{
		ft_putstr_fd(line, 2);
		ft_putstr_fd(": not compatible param\n", 2);
		cb_examplefile();
	}
}

bool	cb_mc_error(t_mapconf mapconf)
{
	if (!mapconf.e_file || !mapconf.w_file || !mapconf.n_file
		|| !mapconf.s_file || mapconf.c_color == -2 || mapconf.f_color == -2)
	{
		cb_param_miss(mapconf);
		return (true);
	}
	else
		return (false);
}

bool	cb_mapln_cnt(char *line)
{
	int	i;
	int	w;
	int	f;
	int	p;

	i = 0;
	w = 0;
	f = 0;
	p = 0;
	while (line[i])
	{
		if (line[i] == '1')
			w++;
		if (line[i] == '0')
			f++;
		if (line[i] == 'S' || line[i] == 'N' || line[i] == 'E'
			|| line[i] == 'W')
			p++;
		i++;
	}
	if (w > 1)
		return (true);
	else
		return (false);
}
