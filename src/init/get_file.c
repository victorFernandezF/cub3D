/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:52:03 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/07 13:52:27 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*cb_fillrows(char *s)
{
	char	*tmp;
	int		i;

	tmp = (char *) malloc((cb_strlen(s) + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int	cb_mrows(char *argv)
{
	int		fd;
	int		rows;
	char	*s;

	fd = open(argv, O_RDONLY);
	if (fd < 1)
		cb_fail("Error\nFailed open file\n");
	rows = 0;
	s = get_next_linem(fd);
	while (s)
	{
		free(s);
		rows++;
		s = get_next_linem(fd);
	}
	/*if (rows < 3)
		cb_fail("Error\nIncorrect map, min 3 pos Y axis\n");*/
	close(fd);
	return (rows);
}

char	**cb_getfile(char *argv)
{
	int		i;
	int		fd;
	char	**file;
	char	*s;

	fd = open(argv, O_RDONLY);
	if (fd < 1)
		cb_fail("Error\nFailed open file\n");
	file = (char **) malloc((cb_mrows(argv) + 1) * sizeof(char *));
	if (!file)
		cb_fail("Error\nFailed allocate memory\n");
	i = 0;
	while (i < cb_mrows(argv))
	{
		s = get_next_linem(fd);
		file[i] = cb_fillrows(s);
		free (s);
		if (!file[i])
			cb_failrows(file, i, fd);
		i++;
	}
	close(fd);
	file[i] = NULL;
	return (file);
}