/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:31:19 by fortega-          #+#    #+#             */
/*   Updated: 2023/10/04 13:43:18 by victofer         ###   ########.fr       */
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

# define DWIN_X 900
# define DWIN_Y 600

# define WIDTH 900
# define HEIGHT 600
# define MSPEED 0.1

# define IMGS_X 64
# define IMGS_Y	64

# define R	"\x1B[31m"	// RED
# define G	"\x1B[32m"	// GREEN
# define B	"\x1B[34m"	// BLUE
# define Y	"\x1B[33m"	// YELLOW
# define M	"\x1B[35m"	// MAGENTA
# define C	"\x1B[36m"	// CYAN
# define W	"\x1B[0m"	// WHITE
# define BR	"\x1B[91m"	// BRIGHT RED
# define BG	"\x1B[92m"	// BRIGHT GREEN
# define BB	"\x1B[94m"	// BRIGT BLUE
# define BY	"\x1B[93m"	// BRIGHT YELLOW
# define BM	"\x1B[95m"	// BRIGHT MAGENTA
# define BC	"\x1B[96m"	// BRIGHT CYAN
# define GR	"\x1B[90m" 	// GRAY

//Size map struct for verification
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

// vector of double (very useful)
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

// Image datas to print pixels in it.
typedef struct s_pimg
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_pimg;

// Camera datas.
typedef struct s_cam
{
	t_vector	start;
	t_vector	end;
	double		x;
}	t_cam;

// Line to print datas.
typedef struct s_line
{
	int		start;
	int		end;
	int		height;
	double	wall_dist;
}	t_line;

typedef struct s_texture
{
	int		num;
	int		with;
	int		height;
	double	wall;
	double	pos;
	int		x;
	void	*ptr;
	t_pimg	datas;
}	t_texture;

//Player struct
typedef struct s_player
{
	char			player;
	t_vector		pos;
	t_vector		grid_coord;
	t_vector		direction;
	t_vector		plane;
	t_point			map;
	t_vector		ray_dir;
	t_vector		side_ds;
	t_vector		delta;
	t_cam			cam;
	t_point			step;
	t_line			line;
	int				hit;
	int				is_side;
	void			*img;
	t_pimg			p_img;
	t_texture		tex;
}	t_player;

//Main struct
typedef struct s_core
{
	void		*mlx;
	void		*win;
	void		*img;
	int			win_x;
	int			win_y;
	char		**file;
	t_mapconf	mapconf;
	t_img		imgs;
	char		**map;
	t_player	player;
}	t_core;

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

int			cb_makecolor(char *str);
int			cb_exit(t_core *core);

// Raycasting and printing
t_player	init_player_datas(t_core core);
t_player	get_cam(t_core core, t_player pl);

t_vector	sum_vectors(t_vector a, t_vector b);
t_vector	sub_vectors(t_vector a, t_vector b);
t_player	rc_start(t_core core);
t_player	get_ray_and_positions(t_player player, int x);
t_player	get_delta_dist(t_player player);
t_player	raycasting(t_player player, char **map);
t_player	calculate_wall_dist(t_player player);
t_player	calculate_height_line(t_player player);
void		print_ceiling(t_core core, t_player pl, int x);
void		print_floor(t_core core, t_player pl, int x);
void		print_3d_map(t_core core, t_player pl, int x);
void		print_player_stuff(t_player player);
void		read_keys(t_core core);
int			input(int key, t_core *core);


#endif