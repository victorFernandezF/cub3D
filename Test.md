int	main(void)
{
	t_data	data;

	// Create a connection to the X server
	data.mlx_ptr = mlx_init();

	// Create a window
	data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, Texture Mapping Example);

	// Load the texture image
	data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, texture.xpm, &data.line_length, &data.bits_per_pixel);

	// Obtain the image data
	data.addr = mlx_get_data_addr(data.img_ptr, &data.bits_per_pixel, &data.line_length, &data.endian);

	// Render the wall
	for (int x = 0; x < 800; x++)
	{
		for (int y = 0; y < 600; y++)
		{
			int tex_x = x % data.line_length;  // Calculate texture coordinates
			int tex_y = y % data.bits_per_pixel;

			// Get the color of the corresponding pixel in the image
			int color = *(unsigned int*)(data.addr + (tex_y * data.line_length) + (tex_x * (data.bits_per_pixel / 8)));

			// Set the pixel color on the wall
			mlx_pixel_put(data.mlx_ptr, data.win_ptr, x, y, color);
		}
	}

	// Display the rendered image
	mlx_loop(data.mlx_ptr);

	return 0;
