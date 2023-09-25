/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:31:19 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/25 11:31:06 by victofer         ###   ########.fr       */
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

// floats coords
typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

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

//Player struct
typedef struct s_player
{
	char			player;
	t_vector		position;
	t_vector		grid_coord;
	t_vector		direction;
	t_vector		plane;
	t_vector		cam_start;
	t_vector		cam_end;
	t_vector		cam_center;
	int				orientation_degree;
	int				vision_degree;
	int				height;
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
t_core		init_player_datas(t_core core);
t_core		rc_start(t_core core);
t_vector	sum_vectors(t_vector a, t_vector b);
t_vector	sub_vectors(t_vector a, t_vector b);
t_core		get_cam(t_core core);

#endif