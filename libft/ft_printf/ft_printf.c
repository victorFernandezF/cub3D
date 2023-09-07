/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:27:05 by fortega-          #+#    #+#             */
/*   Updated: 2022/10/11 12:22:32 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_type(char t, va_list *args, int *size)
{
	if (t == 'c')
		ft_printchar((char) va_arg(*args, int), size);
	else if (t == 's')
		ft_printstr(va_arg(*args, char *), size);
	else if (t == 'p')
	{
		write(1, "0x", 2);
		(*size) += 2;
		ft_printptr(va_arg(*args, size_t), size);
	}
	else if (t == 'd' || t == 'i')
		ft_printnbr(va_arg(*args, int), size);
	else if (t == 'u')
		ft_printuns(va_arg(*args, unsigned int), size);
	else if (t == 'x' || t == 'X')
		ft_printhex(va_arg(*args, unsigned int), size, t);
	else if (t == '%')
		ft_printchar('%', size);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		size;

	i = 0;
	size = 0;
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			ft_type(string[i], &args, &size);
			i++;
		}
		else
		{
			ft_printchar(string[i], &size);
			i++;
		}
	}
	va_end(args);
	return (size);
}
