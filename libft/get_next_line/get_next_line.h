/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:16:44 by fortega-          #+#    #+#             */
/*   Updated: 2022/11/11 12:52:19 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

char	*get_next_line(int fd);
char	*get_next_linem(int fd);
size_t	ft_strlengnl(char *str);
char	*ft_get_buffer(int fd, char *buff);
char	*ft_get_line(char *buff);
char	*ft_strjoingnl(char *s1, char *s2);
char	*ft_strchrgnl(const char *s, int c);
char	*ft_cut_next(char *buff);

#endif
