/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:31:19 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/21 18:32:57 by victofer         ###   ########.fr       */
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

# define IMGS_X 64
# define IMGS_Y	64

//Size map struct for verification
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

//Map configuration struct
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

//Images struct
typedef struct s_img
{
	int		size_x;
	int		size_y;
	void	*n;
	void	*s;
	void	*w;
	void	*e;
}	t_img;

//Projection plane struct
typedef struct s_plane
{
	int 		width;
	int 		height;
	t_point		center;
	int			distance;
}	t_plane;

//Player struct
typedef struct s_player
{
	t_point		position;
	t_point		grid_coord;
	t_point		direction;
	int			orientation_degree;
	int			vision_degree;
	int			height;
	t_plane		plane;
}	t_player;

//Main struct
typedef struct s_core
{
	void		*mlx;
	void		*win;
	int			win_x;
	int			win_y;
	char		**file;
	t_mapconf	mapconf;
	t_img		imgs;
	char		**map;
	t_player	player;
}	t_core;

# define G	"\x1B[32m"	// GREEN
# define W	"\x1B[0m"	// WHITE

//Init fuctions
t_core		cb_init(char **argv);
void		cb_extcheck_map(char *str);
char		**cb_getfile(char *argv);
t_mapconf	cb_getmapconf(char **file);
void		cb_getcolors(t_mapconf *mapconf, char *line, char **file);
int			trgb(int t, int r, int g, int b);
bool		cb_check_params(t_core *core);
char		**cb_getmap(char **file);
char		**cb_getmap_fill(char **file);
bool		cb_check_map(char **map);
bool		cb_chars_map(char **map);
bool		cb_closecheck(t_core *core);
void		cb_check_xpm(t_core *core);

//Utils chars
int			cb_strlen(char *s);
bool		cb_isnum(char c);
bool		cb_isspace(char c);
bool		cb_emptyln(char *str);
char		*cb_fillrows(char *s);
int			cb_maxx(char **file);
char		*cb_fillrows_full(char *s, int size);
char		**cb_split(char const *s, char c);

//Utils memory
void		cb_freemat(char **mat);
void		cb_freemat_rev(char **mat, int i);
void		cb_freecore(t_core *core);
void		cb_free_mc(t_mapconf *mapconf, char **file);

//Utils errors
void		cb_fail(char *str);
void		cb_failrows(char **map, int i, int fd);

//utils extra
void		printmat(char **mat);
void		cb_printmc(t_mapconf *mapconf);


//player datas
t_core init_player_datas(t_core core);

#endif
