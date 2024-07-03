/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:11:15 by jrichir           #+#    #+#             */
/*   Updated: 2024/07/03 16:11:10 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

int	close_window(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	//mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}
 
int on_keypress(int keysym, t_data *data)
{
	(void)data;
	ft_printf("Pressed key: %d\\n", keysym);
	return (0);
}
 
int main(void)
{
	t_data	data;
	int		t_size;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "hi :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
 
	// Register key release hook
	mlx_hook(data.win_ptr, ON_KEYRELEASE, 0, &on_keypress, &data);
 
	// Register destroy hook
	mlx_hook(data.win_ptr, ON_DESTROY, 0, &on_destroy, &data);
	
	t_size = TILE_SIZE;
	data.textures[0] = mlx_xpm_file_to_image(data.mlx_ptr, TXGRASS, &t_size, &t_size);
	data.textures[1] = mlx_xpm_file_to_image(data.mlx_ptr, TXROCK, &t_size, &t_size);
	data.textures[2] = mlx_xpm_file_to_image(data.mlx_ptr, TXPLAYER, &t_size, &t_size);
	data.textures[3] = mlx_xpm_file_to_image(data.mlx_ptr, TXEXIT, &t_size, &t_size);
	data.textures[4] = mlx_xpm_file_to_image(data.mlx_ptr, TXCOLLECTIBLE, &t_size, &t_size);

	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[0], 0, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[0], TILE_SIZE, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[0], TILE_SIZE * 2, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[0], TILE_SIZE * 3, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[0], TILE_SIZE * 4, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1], TILE_SIZE, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[2], TILE_SIZE * 2, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[3], TILE_SIZE * 3, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[4], TILE_SIZE * 4, 0);

	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	return (0);
}
