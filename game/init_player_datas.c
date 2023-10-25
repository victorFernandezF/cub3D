/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_datas.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:09:29 by victofer          #+#    #+#             */
/*   Updated: 2023/10/25 16:12:47 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Checks if a character is a player or not.
static int	is_player(char c)
{
	return (c == 'N' || c == 'W' || c == 'S' || c == 'E');
}

// Returns a vector with the initial position of the player
// in the map.
t_vector	get_pos(t_mapconf mapconf, char **map)
{
	int			i;
	int			j;
	t_vector	tmp;

	i = -1;
	while (++i < mapconf.map_y)
	{
		j = -1;
		while (++j < mapconf.map_x)
		{
			if (is_player(map[i][j]))
			{
				tmp.x = j;
				tmp.y = i;
			}
		}
	}
	return (tmp);
}

// Set the plane depending on the initial direccion of the character.
static t_player	get_plane(t_core core, t_player pl, int x, int y)
{
	if (core.map[y][x] == 'E')
	{
		pl.dir.x = 1;
		pl.plane.y = 0.66;
	}
	if (core.map[y][x] == 'N')
	{
		pl.dir.y = -1;
		pl.plane.x = 0.66;
	}
	if (core.map[y][x] == 'W')
	{
		pl.dir.x = -1;
		pl.plane.y = -0.66;
	}
	if (core.map[y][x] == 'S')
	{
		pl.dir.y = 1;
		pl.plane.x = -0.66;
	}
	return (pl);
}

// Creates a new image in which the map will be printed
// Get its datas and stored in a structure. Later will be
// inserted into de winsow.
t_pimg	get_image_datas(t_core core)
{
	t_pimg	img;

	img.img_ptr = mlx_new_image(core.mlx, DWIN_X, DWIN_Y);
	img.data = (int *)mlx_get_data_addr(img.img_ptr,
			&img.bpp, &img.size_l, &img.endian);
	return (img);
}

// Set the initial values of the player struct.
t_player	init_player_datas(t_core core)
{
	t_player	player;
	int			x;
	int			y;

	player.line.height = 0;
	player.side = '0';
	player.line.start = 0;
	player.line.end = 0;
	player.plane.x = 0;
	player.plane.y = 0;
	player.dir.x = 0;
	player.dir.y = 0;
	player.grid_coord = get_pos(core.mapconf, core.map);
	x = player.grid_coord.x;
	y = player.grid_coord.y;
	player.player = core.map[y][x];
	player.pos.x = player.grid_coord.x + 0.5;
	player.pos.y = player.grid_coord.y + 0.5;
	player = get_plane(core, player, x, y);
	player.p_img = get_image_datas(core);
	return (player);
}
