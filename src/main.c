/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:11:15 by jrichir           #+#    #+#             */
/*   Updated: 2024/06/27 12:51:08 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(int argc, char **argv)
{
	t_data	img;
	void	*mlx;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 360, 360);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
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
