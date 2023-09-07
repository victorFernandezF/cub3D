/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:24:06 by fortega-          #+#    #+#             */
/*   Updated: 2022/10/08 11:37:09 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(long int ln)
{
	int	i;

	i = 0;
	if (ln < 0)
	{
		ln = -ln;
		i++;
	}
	if (ln == 0)
		return (i + 1);
	while (ln > 0)
	{
		ln = ln / 10;
		i++;
	}
	return (i);
}

static char	*ft_stralloc(int n)
{
	char	*str;

	str = (char *) malloc ((n + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	return (str);
}

static char	*ft_strfill(char *str, long int ln, int size)
{
	int			i;

	i = size - 1;
	if (ln < 0)
	{
		str[0] = '-';
		ln = -ln;
	}
	if (ln == 0)
	{
		str[0] = '0';
		str[size] = '\0';
		return (str);
	}
	while (ln > 0)
	{
		str[i] = (ln % 10) + '0';
		ln = ln / 10;
		i--;
	}
	str[size] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			size;
	long int	ln;

	ln = n;
	size = ft_size(ln);
	str = ft_stralloc(size);
	if (str == NULL)
		return (NULL);
	ft_strfill(str, ln, size);
	return (str);
}
