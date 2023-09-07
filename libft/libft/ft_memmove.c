/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:16:52 by fortega-          #+#    #+#             */
/*   Updated: 2022/09/26 18:01:47 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*cdst;
	unsigned const char	*csrc;

	cdst = (unsigned char *) dst;
	csrc = (unsigned const char *) src;
	i = len;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (cdst > csrc)
		while (i--)
			cdst[i] = csrc[i];
	else
	{
		i = 0;
		while (i < len)
		{
			cdst[i] = csrc[i];
			i++;
		}
	}
	return (dst);
}
