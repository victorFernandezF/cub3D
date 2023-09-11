/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:24:51 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/11 13:24:41 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*bool	cb_xpmcheck(char *xpm)
{

}*/

bool	cb_extcheck_text(char *str)
{
	int		i;
	int		c;
	char	*xpm;

	xpm = ".xpm";
	if (!str)
		return (false);
	c = 3;
	i = ft_strlen(str) - 1;
	while (c > -1)
	{
		if (xpm[c] != str[i])
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd(str, 2);
			ft_putstr_fd("\nNeeded .xpm texture\n", 2);
			return (false);
		}
		c--;
		i--;
	}
	return (true);
}

void	cb_extcheck_map(char *str)
{
	int		i;
	int		c;
	char	*cub;

	cub = ".cub";
	c = 3;
	i = ft_strlen(str) - 1;
	while (c > -1)
	{
		if (cub[c] != str[i])
			cb_fail("Error\nI need .cub map\n");
		c--;
		i--;
	}
}

bool	cb_checkfile(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nFile: <", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd("> not exist\n", 2);
		close(fd);
		return (false);
	}
	else
		return (true);
}

bool	cb_check_params(t_core *core)
{
	if (core->mapconf.c_color == -1 || core->mapconf.f_color == -1)
	{
		ft_putstr_fd("Error\nColor only [C-F] [0-255], [0-255], [0-255]\n", 2);
		return (false);
	}
	if (!cb_extcheck_text(core->mapconf.n_file)
		|| !cb_extcheck_text(core->mapconf.s_file)
		|| !cb_extcheck_text(core->mapconf.e_file)
		|| !cb_extcheck_text(core->mapconf.w_file))
		return (false);
	if (!cb_checkfile(core->mapconf.n_file)
		|| !cb_checkfile(core->mapconf.s_file)
		|| !cb_checkfile(core->mapconf.e_file)
		|| !cb_checkfile(core->mapconf.w_file))
		return (false);
	/*if (!cb_xpmcheck(core->mapconf.n_file)
		|| !cb_xpmcheck(core->mapconf.s_file)
		|| !cb_xpmcheck(core->mapconf.e_file)
		|| !cb_xpmcheck(core->mapconf.w_file))
		return (false);*/
	return (true);
}
