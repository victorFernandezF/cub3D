/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printletters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:01:26 by fortega-          #+#    #+#             */
/*   Updated: 2022/10/11 11:32:20 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printchar(char c, int *size)
{
	write(1, &c, 1);
	(*size)++;
}

void	ft_printstr(char *str, int *size)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_printstr("(null)", size);
		return ;
	}	
	while (str[i])
	{
		ft_printchar(str[i], size);
		i++;
	}
}
