/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:29:43 by victofer          #+#    #+#             */
/*   Updated: 2023/10/25 13:21:12 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	print_test2(t_player *player)
{
	printf(" player ray dir(%.2f, %.2f)%s\n",
		player->ray_dir.x, player->ray_dir.y, G);
	printf(" player side dist(%.2f, %.2f)%s\n",
		player->side_ds.x, player->side_ds.y, G);
	printf(" player delta dist(%.2f, %.2f)%s\n",
		player->delta.x, player->delta.y, G);
	printf(" player step(%i, %i)%s\n",
		player->step.x, player->step.y, G);
	printf(" player wall dist (%.2f)%s\n",
		player->line.wall_dist, G);
	printf(" player line height(%i,%i)%s\n",
		player->line.start, player->line.end, G);
	printf(" player line points (%i, %i)%s\n\n",
		player->line.start, player->line.end, G);
	printf("test color (%i)%s\n\n", cb_makecolor("0,0,0"), W);
}

void	print_player_stuff(t_player *player)
{
	printf("%s   PLAYER STUFF   \n", G);
	printf(" player char  [%c]\n", player->player);
	printf(" player grid pos  (%.2f, %.2f)\n",
		player->grid_coord.x, player->grid_coord.y);
	printf(" player real pos (%.2f, %.2f)\n",
		player->pos.x, player->pos.y);
	printf(" player direction (%.2f, %.2f)\n",
		player->dir.x, player->dir.y);
	printf(" player plane (%.2f, %.2f)%s\n",
		player->plane.x, player->plane.y, G);
	printf(" player map pos(%i, %i)%s\n",
		player->map.x, player->map.y, G);
	print_test2(player);
}

void	printmap(char **mat)
{
	int	i;
	int	j;

	i = 0;
	while (mat[i])
	{
		j = 0;
		while (mat[i][j])
		{
			if (mat[i][j] == 'X')
				ft_printf("%s%c%s", G, mat[i][j], W);
			else
				ft_printf("%c", mat[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	testing_border_detector(t_core *core)
{
	printf("dir: (%f, %f)\npos: (%f, %f)\n%c\n  %c\n%c P %c \n  %c\n\n",
		core->player.pos.x, core->player.pos.y,
		core->player.dir.x, core->player.dir.y,
		core->map[(int)(core->player.pos.y)][(int)(core->player.pos.x)],
		core->map[(int)(core->player.pos.y - 1)][(int)(core->player.pos.x)],
		core->map[(int)(core->player.pos.y)][(int)(core->player.pos.x - 1)],
		core->map[(int)(core->player.pos.y)][(int)(core->player.pos.x + 1)],
		core->map[(int)(core->player.pos.y + 1)][(int)(core->player.pos.x)]);
}
