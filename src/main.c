/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:11:15 by jrichir           #+#    #+#             */
/*   Updated: 2024/06/27 13:17:02 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "My first MLX window");
	img.img = mlx_new_image(mlx, 360, 360);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	my_mlx_pixel_put(&img, 15, 15, 0x00FF55FF);
	my_mlx_pixel_put(&img, 16, 15, 0x00FF55FF);
	my_mlx_pixel_put(&img, 15, 16, 0x00FF55FF);
	my_mlx_pixel_put(&img, 16, 16, 0x00FF55FF);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

/*
//int	main(int argc, char **argv)
int	main(int argc, char **argv)
{
	t_data	img;
	void	*mlx;
	//void	*mlx_win;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 360, 360);
	//mlx_win = mlx_new_window(mlx, 600, 600, "My first MLX window");
	//mlx_loop(mlx);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	return (0);
}
*/
