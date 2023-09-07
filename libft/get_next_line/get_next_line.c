/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:00:23 by fortega-          #+#    #+#             */
/*   Updated: 2023/01/13 19:07:20 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_buffer(int fd, char *buff)
{
	char	*temp;
	int		reads;

	temp = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	reads = 1;
	while (reads != 0 && !ft_strchrgnl(buff, '\n'))
	{
		reads = read(fd, temp, BUFFER_SIZE);
		if (reads == -1)
		{
			free (buff);
			free (temp);
			return (NULL);
		}
		temp[reads] = '\0';
		buff = ft_strjoingnl(buff, temp);
	}
	free (temp);
	return (buff);
}

char	*ft_get_line(char *buff)
{
	char	*str;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	str = (char *) malloc ((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		str[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		str[i] = buff[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_cut_next(char *buff)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free (buff);
		return (NULL);
	}
	temp = (char *) malloc ((ft_strlengnl(buff) - i + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while (buff[i])
		temp[j++] = buff[i++];
	temp[j] = '\0';
	free (buff);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = ft_get_buffer(fd, buff);
	if (!buff)
		return (NULL);
	str = ft_get_line(buff);
	buff = ft_cut_next(buff);
	return (str);
}

char	*get_next_linem(int fd)
{
	static char	*buff[65535];
	char		*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff[fd] = ft_get_buffer(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	str = ft_get_line(buff[fd]);
	buff[fd] = ft_cut_next(buff[fd]);
	return (str);
}
