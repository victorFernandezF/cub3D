/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:31:19 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/08 14:48:16 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>

# define DWIN_X 640
# define DWIN_Y 480

typedef struct s_mapconf
{
	char	*n_file;
	char	*s_file;
	char	*w_file;
	char	*e_file;
	int		f_color;
	int		c_color;
	int		map_x;
	int		map_y;
}	t_mapconf;


typedef struct s_core
{
	void		*mlx;
	void		*win;
	int			win_x;
	int			win_y;
	char		**file;
	t_mapconf	mapconf;
	char		**map;
}	t_core;


//Init fuctions
t_core		cb_init(char **argv);
char		**cb_getfile(char *argv);
t_mapconf	cb_getmapconf(char **file);
void		cb_getcolors(t_mapconf *mapconf, char *line);
int			trgb(int t, int r, int g, int b);

//Utils chars
int			cb_strlen(char *s);
bool		cb_isnum(char c);
bool		cb_isspace(char c);
bool		cb_emptyln(char *str);

//Utils memory
void		cb_freemat(char **mat);
void		cb_freemat_rev(char **mat, int i);
void		cb_freecore(t_core *core);

//Utils errors
void		cb_fail(char *str);
void		cb_failrows(char **map, int i, int fd);

//utils extra
void		printmat(char **mat);
void		cb_printmc(t_mapconf *mapconf);

#endif
