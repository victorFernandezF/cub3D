
#include <math.h>
#include "../includes/cub3d.h"

t_core rc_start(t_core core)
{
	int i;
	double cam_x;
	t_vector ray_dir;

	i = -1;
	while (++i < core.mapconf.map_x){
		cam_x = 2 * i / (double)core.mapconf.map_x - 1;
		ray_dir.x = core.player.direction.x + core.player.plane.x * cam_x;
		ray_dir.y = core.player.direction.y + core.player.plane.y * cam_x;
		printf("cam_x: %.2f\n", cam_x);
		printf("(%.2f, %.2f)\n", ray_dir.x, ray_dir.y);
	}
	return (core);
}