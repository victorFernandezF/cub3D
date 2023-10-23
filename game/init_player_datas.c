/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_datas.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:09:29 by victofer          #+#    #+#             */
/*   Updated: 2023/10/23 18:13:41 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_player(char c)
{
	return (c == 'N' || c == 'W' || c == 'S' || c == 'E');
}

int	get_pos(t_mapconf mapconf, char **map, char pos)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	x = 0;
	y = 0;
	while (++i < mapconf.map_y)
	{
		j = -1;
		while (++j < mapconf.map_x)
		{
			if (is_player(map[i][j]))
			{
				x = j;
				y = i;
			}
		}
	}
	if (pos == 'x')
		return (x);
	return (y);
}

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

t_pimg	get_image_datas(t_core core)
{
	t_pimg	img;

	img.img_ptr = mlx_new_image(core.mlx, DWIN_X, DWIN_Y);
	img.data = (int *)mlx_get_data_addr(img.img_ptr,
			&img.bpp, &img.size_l, &img.endian);
	return (img);
}

void	check_max_speed(void)
{
	if (MSPEED >= 2)
	{
		ft_putstr_fd("Error\nMovement speed is too hight\n", 2);
		exit(-1);
	}
}

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
	player.grid_coord.x = get_pos(core.mapconf, core.map, 'x');
	player.grid_coord.y = get_pos(core.mapconf, core.map, 'y');
	x = player.grid_coord.x;
	y = player.grid_coord.y;
	player.player = core.map[y][x];
	player.pos.x = player.grid_coord.x + 0.5;
	player.pos.y = player.grid_coord.y + 0.5;
	player = get_plane(core, player, x, y);
	player = get_cam(core, player);
	player.p_img = get_image_datas(core);
	return (player);
}
