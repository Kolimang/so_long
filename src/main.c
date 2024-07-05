/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:11:15 by jrichir           #+#    #+#             */
/*   Updated: 2024/07/04 19:45:21 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	close_window(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

// original 2nd line : mlx_destroy_display(data->mlx_ptr);
// (mlx_destroy_display() does not seem to exist on opengl version)
int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
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

// Check input (valid map path/name ?, valid number of args ?)
// Get map (gnl)
// Check map
//   \__ [v] holes / invalid character ?
//   \__ [v] enclosed by walls ?
//   \__ [v] exactly 1 player/exit ?
//   \__ [v] at least 1 collectible ?
//   \__ not too big for the screen ?
//   \__ playable ? (flood fill)
// Load textures
// Register hooks (mlx_hook())
// Handle input (valid move ? exit reached ? -> free everything and quit)
//    \__ Print moves to console (print/increment only if move is valid)
// Update map
// Prepare image to draw
//    \__ if first time or EXPOSE event triggered, redraw the whole map
//    \__ else draw the modified squares (player moved, item collected...)
// Draw image to window
// Loop over the MLX pointer
int	init_structures(t_data *data, t_map *map)
{
	data->map = map;
	data->map->nb_exit = 0;
	data->map->nb_player_start = 0;
	data->map->nb_collectibles = 0;
	data->map->valid = 0;
	return (0);
}
void	load_textures(t_data *data)
{
	int	size = TILE_SIZE;

	data->textures[0] = mlx_xpm_file_to_image(data->mlx_ptr, TXGRASS, &size, &size);
	data->textures[1] = mlx_xpm_file_to_image(data->mlx_ptr, TXROCK, &size, &size);
	data->textures[2] = mlx_xpm_file_to_image(data->mlx_ptr, TXPLAYER, &size, &size);
	data->textures[3] = mlx_xpm_file_to_image(data->mlx_ptr, TXEXIT, &size, &size);
	data->textures[4] = mlx_xpm_file_to_image(data->mlx_ptr, TXCOLLECTIBLE, &size, &size);
}

void	blit_image(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0], 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0], TILE_SIZE, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0], TILE_SIZE * 2, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0], TILE_SIZE * 3, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0], TILE_SIZE * 4, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[1], TILE_SIZE, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[2], TILE_SIZE * 2, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[3], TILE_SIZE * 3, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[4], TILE_SIZE * 4, 0);
}

int	main(int argc, char *argv[])
{
	t_data		data;
	t_map		map;
	t_player	player;

	init_structures(&data, &map);
	if (check_input(argc, argv) == 1)
		return (1);
	if (check_lines(&data, argv[1]) == 1)
		return (1);
	create_grid(&data, argv[1]);
	if(check_grid(&data) == 1)
		return (array_str_free(data.map->grid, array_str_len(data.map->grid)), 1);
	array_str_print(data.map->grid, '\n');
	create_grid(&data, argv[1]);
	array_str_print(data.map->grid, '\n');
	data.winw = data.map->width * TILE_SIZE;
	data.winh = data.map->height * TILE_SIZE;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.winw, data.winh, "Soooo long");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	mlx_hook(data.win_ptr, ON_KEYRELEASE, 0, &on_keypress, &data);
	mlx_hook(data.win_ptr, ON_DESTROY, 0, &on_destroy, &data);
	load_textures(&data);
	blit_image(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
