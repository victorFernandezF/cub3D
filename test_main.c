

# include "mlx/mlx.h"
# include <stdio.h>

typedef struct s_pimg
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_pimg;

int main(void)
{
	void *ptr;
	void *win;
	void *imgptr;
	void *newimgptr;
	t_pimg img;
	t_pimg new;
	int i = -1;
	int w = 398;
	int h = 256;


	ptr = mlx_init();
	win = mlx_new_window(ptr, 500, 500, "test");
	newimgptr = mlx_new_image(ptr, 64, 64);
	imgptr = mlx_xpm_file_to_image(ptr, "textures/test/test.xpm", &w, &h);
	img.data = (int *)mlx_get_data_addr(imgptr, &img.bpp, &img.size_l, &img.endian);
	new.data = (int *)mlx_get_data_addr(newimgptr, &img.bpp, &img.size_l, &img.endian);	
	while (++i < w)
	{
		int j = -1;
		while (++j < h)
			new.data[j * w + i] = img.data[j * w + i];
	}
	mlx_put_image_to_window(ptr, win, newimgptr, 0, 0);

	printf("%i\n", img.data[5]);
	printf("%i\n", img.data[25]);
	mlx_loop(ptr);
}