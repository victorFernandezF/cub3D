/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:31:19 by fortega-          #+#    #+#             */
/*   Updated: 2023/10/23 18:14:35 by victofer         ###   ########.fr       */
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
# include "./cub3d_structs.h"

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
bool		cb_map_elines(char **map);
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
void		printcore(t_core core);

// --  RAYCASTING AND PRINTING MAP  --
void		check_max_speed(void);
// Get datas
int			get_pos(t_mapconf mapconf, char **map, char pos);
t_player	init_player_datas(t_core core);
t_player	get_cam(t_core core, t_player pl);

// start raycasting
t_player	rc_start(t_core core);
t_player	get_ray_and_positions(t_player player, int x);
t_player	get_delta_dist(t_player player);
t_player	raycasting(t_player player, char **map);
t_player	calculate_wall_dist(t_player player);
t_player	calculate_height_line(t_player player);

// printing map
void		print_ceiling(t_core core, t_player pl, int x);
void		print_floor(t_core core, t_player pl, int x);
void		print_texture(t_core core, t_player pl, int x);
void		print_3d_map(t_core core, t_player pl, int x);
t_texture	get_correct_texture(t_core core, t_player pl);
t_pimg		get_image_datas(t_core core);
int			get_color_of_texture(t_core core, t_player pl, int x, int y);
t_printtex	get_texture_datas(t_player pl);

//movements
void		read_keys(t_core core);
int			input(int key, t_core *core);
t_core		*rotation(t_core *core, char direction);
t_core		*move_front(t_core *core);
t_core		*move_back(t_core *core);
t_core		*move_left(t_core *core);
t_core		*move_right(t_core *core);

// vectors operations
t_vector	sum_vectors(t_vector a, t_vector b);
t_vector	sub_vectors(t_vector a, t_vector b);

// TESTING
void		print_player_stuff(t_player *player);
void		testing_border_detector(t_core *core);
void		printmap(char **mat);
#endif