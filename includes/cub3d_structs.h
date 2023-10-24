/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:46:17 by victofer          #+#    #+#             */
/*   Updated: 2023/10/24 18:21:37 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

// WINDOWS AND IMAGE SIZES
# define DWIN_X 900
# define DWIN_Y 600
# define IMGS_X 64
# define IMGS_Y	64

// MOVEMENT SPEEDS
# define RSPEED 0.1
# define MSPEED 0.3

// KEYS 
# define K_ESC 53
# define K_W 13
# define K_S 1
# define K_A 0
# define K_D 2
# define K_L_ARROW 123
# define K_R_ARROW 124

// COLOURS
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

// -----  S T R U C T S -----

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

// Texture datas
typedef struct s_texture
{
	void	*ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_texture;

// Datas of the trexture such as positions, color ..., 
typedef struct s_printtex
{
	unsigned int	color;
	int				tex_x;
	double			wallx;
	double			step;
	double			texpos;
	double			tex_y;
	double			tex_pos;
}	t_printtex;

//Player struct
typedef struct s_player
{
	char			side;
	char			player;
	t_vector		pos;
	t_vector		grid_coord;
	t_vector		dir;
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
	t_pimg			p_img;
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
	t_texture	tex_n;
	t_texture	tex_s;
	t_texture	tex_e;
	t_texture	tex_w;
}	t_core;

#endif