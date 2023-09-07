/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbrs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:26:52 by fortega-          #+#    #+#             */
/*   Updated: 2022/10/11 12:23:26 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printptr(size_t nbr, int *size)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr == 0)
	{
		ft_printchar('0', size);
		return ;
	}
	if (nbr > 15)
	{
		ft_printptr(nbr / 16, size);
		ft_printchar(base[nbr % 16], size);
	}
	else
		ft_printchar(base[nbr], size);
}

void	ft_printnbr(int nbr, int *size)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*size) += 11;
		return ;
	}
	if (nbr == 0)
	{
		ft_printchar('0', size);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		(*size)++;
	}
	if (nbr > 9)
	{
		ft_printnbr(nbr / 10, size);
		ft_printchar(((nbr % 10) + '0'), size);
	}
	else
		ft_printchar(nbr + '0', size);
}

void	ft_printuns(unsigned int nbr, int *size)
{
	if (nbr == 0)
	{
		ft_printchar('0', size);
		return ;
	}
	if (nbr > 9)
	{
		ft_printuns(nbr / 10, size);
		ft_printchar(((nbr % 10) + '0'), size);
	}
	else
		ft_printchar(nbr + '0', size);
}

void	ft_printhex(unsigned int nbr, int *size, char t)
{
	char	*base;

	if (t == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr == 0)
	{
		ft_printchar('0', size);
		return ;
	}
	if (nbr > 15)
	{
		ft_printhex(nbr / 16, size, t);
		ft_printchar(base[nbr % 16], size);
	}
	else
		ft_printchar(base[nbr], size);
}
