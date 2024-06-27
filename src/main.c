/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:11:15 by jrichir           #+#    #+#             */
/*   Updated: 2024/06/27 16:04:08 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_window(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	print_dot(t_data *img)
{
	my_mlx_pixel_put(img, 40, 20, 0x00FF55FF);
	my_mlx_pixel_put(img, 39, 21, 0x00FF55FF);
	my_mlx_pixel_put(img, 40, 21, 0x00FF55FF);
	my_mlx_pixel_put(img, 41, 21, 0x00FF55FF);
	my_mlx_pixel_put(img, 39, 22, 0x00FF55FF);
	my_mlx_pixel_put(img, 40, 22, 0x00FF55FF);
	my_mlx_pixel_put(img, 41, 22, 0x00FF55FF);
	my_mlx_pixel_put(img, 40, 23, 0x00FF55FF);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L << 0, close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

/*
int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
	int		y;

	x = 25;
	y = 50;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "My first MLX window");
	img.img = mlx_new_image(mlx, 360, 360);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	print_dot(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, 2, 1L<<0, close_window, &mlx_win);
	mlx_loop(mlx);
	return (0);
}


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
