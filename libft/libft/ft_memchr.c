/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 08:57:24 by fortega-          #+#    #+#             */
/*   Updated: 2022/09/26 18:04:48 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*str;
	unsigned char		pc;
	size_t				i;

	str = (unsigned const char *) s;
	pc = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == pc)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}
