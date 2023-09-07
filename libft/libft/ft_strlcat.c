/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:44:09 by fortega-          #+#    #+#             */
/*   Updated: 2022/09/23 15:11:47 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	c;
	size_t	bd;
	size_t	bs;

	bd = ft_strlen(dst);
	bs = ft_strlen(src);
	i = bd;
	c = 0;
	if (size == 0 || size <= bd)
		return (bs + size);
	while (src[c] && c < (size - bd - 1))
	{
		dst[i] = src[c];
		i++;
		c++;
	}
	dst[i] = '\0';
	return (bd + bs);
}
