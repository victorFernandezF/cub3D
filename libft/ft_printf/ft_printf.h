/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:32:49 by fortega-          #+#    #+#             */
/*   Updated: 2022/10/11 12:26:49 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *string, ...);
void	ft_printchar(char c, int *size);
void	ft_printstr(char *str, int *size);
void	ft_printptr(size_t ptr, int *size);
void	ft_printnbr(int nbr, int *size);
void	ft_printuns(unsigned int nbr, int *size);
void	ft_printhex(unsigned int nbr, int *size, char t);

#endif