/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:28:36 by fortega-          #+#    #+#             */
/*   Updated: 2023/09/08 14:51:57 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	rgb_to_int(double r, double g, double b)
{
	int	color;

	color = 0;
	color |= (int)(b * 255);
	color |= (int)(g * 255) << 8;
	color |= (int)(r * 255) << 16;
	return (color);
}

int	trgb_to_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	main(void)
{
	printf("test colores\n");

	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 640, 480, "TRGB test");

	mlx_pixel_put(mlx, win, 640 / 2, 480 / 2, 1318440);
	//mlx_pixel_put(mlx, win, 640 / 2, 480 / 2, trgb_to_int(0, 0, 255, 255));
	mlx_loop(mlx);
	return (0);
}
