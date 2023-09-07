/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega-@student.42malaga.com <fortega-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:54:03 by fortega-          #+#    #+#             */
/*   Updated: 2022/12/13 16:18:58 by fortega-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_rows(char *str, char s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] != s)
		{
			c++;
			while (str[i] && str[i] != s)
				i++;
			if (str[i] == '\0')
				return (c);
		}
		i++;
	}
	return (c);
}

static void	ft_freestr(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

static char	*ft_matfill(const char *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = ((char *)ft_calloc(i + 1, sizeof(char)));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**mat;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	mat = (char **)malloc(((ft_rows((char *) s, c)) + 1) * sizeof(char *));
	if (mat == NULL)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			mat[i] = ft_matfill(s, c);
			if (mat[i] == NULL)
				ft_freestr(mat, i);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	mat[i] = NULL;
	return (mat);
}
