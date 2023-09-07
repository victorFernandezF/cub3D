/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:20:22 by fortega-          #+#    #+#             */
/*   Updated: 2022/09/27 08:21:34 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	f;

	i = 0;
	if (needle[i] == '\0')
		return ((char *) haystack);
	while (haystack[i] != '\0' && i < n)
	{
		f = 0;
		while (haystack[i + f] != '\0' && haystack[i + f] == needle[f]
			&& (i + f) < n)
		{
			if (needle[f + 1] == '\0')
				return ((char *)&haystack[i]);
			f++;
		}
		i++;
	}
	return (NULL);
}
