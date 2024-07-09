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
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

// original 2nd line : mlx_destroy_display(nfo->mlx);
// (mlx_destroy_display() does not seem to exist on opengl version)
int	on_destroy(t_nfo *nfo)
{
	mlx_destroy_window(nfo->mlx, nfo->windw);
	free(nfo->mlx);
	exit(0);
	return (0);
}

void	move(t_nfo *nfo, int new_x, int new_y, int d)
{
	int	x;
	int	y;

	x = nfo->hero->x;
	y = nfo->hero->y;
	new_x += nfo->hero->x;
	new_y += nfo->hero->y;
	if (nfo->map->grid[new_y][new_x] != '1')
	{
		nfo->hero->moves++;
		ft_printf("moves: %d\n", nfo->hero->moves);
		if (nfo->map->grid[new_y][new_x] == 'C')
		{
			nfo->hero->nb_collected++;
			mlx_put_image_to_window(nfo->mlx, nfo->windw, nfo->gfx[0], TILE_SZ * new_x, TILE_SZ * new_y);
			if (nfo->hero->nb_collected == nfo->map->nb_collectibles)
				mlx_put_image_to_window(nfo->mlx, nfo->windw, nfo->gfx[2], TILE_SZ * nfo->map->exit_x, TILE_SZ * nfo->map->exit_y);
		}
		if (nfo->map->grid[new_y][new_x] == 'E')
		{
			if (nfo->hero->nb_collected == nfo->map->nb_collectibles)
			{
				ft_printf("- - - - -\nWell done! You exited the level in %d moves.\n ~~ The End ~~\n", nfo->hero->moves);
				on_destroy(nfo);
			}
		}
		if (nfo->map->grid[new_y][new_x] != 'E')
			nfo->map->grid[new_y][new_x] = 'P';
		if (nfo->map->grid[y][x] != 'E')
		{
			nfo->map->grid[y][x] = '0';
			mlx_put_image_to_window(nfo->mlx, nfo->windw, nfo->gfx[0], TILE_SZ * x, TILE_SZ * y);
		}
		else
		{
			mlx_put_image_to_window(nfo->mlx, nfo->windw, nfo->gfx[3], TILE_SZ * x, TILE_SZ * y);
		}
		mlx_put_image_to_window(nfo->mlx, nfo->windw, nfo->gfx[d], TILE_SZ * new_x, TILE_SZ * new_y);
		nfo->hero->x = new_x;
		nfo->hero->y = new_y;
	}
}

int	on_keypress(int key, t_nfo *nfo)
{
	if (key == 123)
		move(nfo, -1, 0, 6); // left
	else if (key == 124)
		move(nfo, 1, 0, 5); // right
	else if (key == 125)
		move(nfo, 0, 1, 7); // down
	else if (key == 126)
		move(nfo, 0, -1, 8); // up
	else if (key == 53)
	{
		// prepare to exit cleanly (frees, ...), here or in the main ?
		ft_printf("quit\n");
		on_destroy(nfo);
	}
	return (0);
}

int	init_structures(t_nfo *nfo, t_map *map, t_player *hero)
{
	nfo->hero = hero;
	nfo->hero->moves = 0;
	nfo->hero->nb_collected = 0;
	nfo->map = map;
	nfo->map->nb_exit = 0;
	nfo->map->exit_x = 0;
	nfo->map->exit_y = 0;
	nfo->map->nb_player_start = 0;
	nfo->map->nb_collectibles = 0;
	nfo->map->valid = 0;
	return (0);
}

void	load_textures(t_nfo *nfo)
{
	int	size;

	size = TILE_SZ;
	nfo->gfx[0] = mlx_xpm_file_to_image(nfo->mlx, TXGRASS, &size, &size);
	nfo->gfx[1] = mlx_xpm_file_to_image(nfo->mlx, TXROCK, &size, &size);
	nfo->gfx[2] = mlx_xpm_file_to_image(nfo->mlx, TXEXIT_O, &size, &size);
	nfo->gfx[3] = mlx_xpm_file_to_image(nfo->mlx, TXEXIT_C, &size, &size);
	nfo->gfx[4] = mlx_xpm_file_to_image(nfo->mlx, TXCOLLECTIBLE, &size, &size);
	nfo->gfx[5] = mlx_xpm_file_to_image(nfo->mlx, TXPLAYER_R, &size, &size);
	nfo->gfx[6] = mlx_xpm_file_to_image(nfo->mlx, TXPLAYER_L, &size, &size);
	nfo->gfx[7] = mlx_xpm_file_to_image(nfo->mlx, TXPLAYER_D, &size, &size);
	nfo->gfx[8] = mlx_xpm_file_to_image(nfo->mlx, TXPLAYER_U, &size, &size);
}

void	blit_image(t_nfo *nfo)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < nfo->map->height)
	{
		x = 0;
		while (x < nfo->map->width)
		{
			mlx_put_image_to_window(nfo->mlx, nfo->windw, nfo->gfx[0], TILE_SZ * x, TILE_SZ * y);
			c = nfo->map->grid[y][x];
			if (c == '1')
				mlx_put_image_to_window(nfo->mlx, nfo->windw, nfo->gfx[1], TILE_SZ * x, TILE_SZ * y);
			else if (c == 'P')
				mlx_put_image_to_window(nfo->mlx, nfo->windw, nfo->gfx[7], TILE_SZ * x, TILE_SZ * y);
			else if (c == 'E')
				mlx_put_image_to_window(nfo->mlx, nfo->windw, nfo->gfx[3], TILE_SZ * x, TILE_SZ * y);
			else if (c == 'C')
				mlx_put_image_to_window(nfo->mlx, nfo->windw, nfo->gfx[4], TILE_SZ * x, TILE_SZ * y);
			x++;
		}
		y++;
	}
}

int	main(int argc, char *argv[])
{
	t_nfo		nfo;
	t_map		map;
	t_player	hero;

	init_structures(&nfo, &map, &hero);
	if (check_input(argc, argv) == 1)
		return (1);
	if (check_lines(&nfo, argv[1]) == 1)
		return (1);
	create_grid(&nfo, argv[1]);
	if (check_grid(&nfo) == 1)
		return (array_str_free(nfo.map->grid, array_str_len(nfo.map->grid)), 1);
	create_grid(&nfo, argv[1]);
	array_str_print(nfo.map->grid, '\n');
	nfo.hero->x = nfo.map->start_x;
	nfo.hero->y = nfo.map->start_y;
	nfo.winw = nfo.map->width * TILE_SZ;
	nfo.winh = nfo.map->height * TILE_SZ;
	nfo.mlx = mlx_init();
	if (!nfo.mlx)
		return (1);
	nfo.windw = mlx_new_window(nfo.mlx, nfo.winw, nfo.winh, GM_NAME);
	if (!nfo.windw)
		return (free(nfo.mlx), 1);
	mlx_hook(nfo.windw, ON_KEYRELEASE, 0, &on_keypress, &nfo);
	mlx_hook(nfo.windw, ON_DESTROY, 0, &on_destroy, &nfo);
	load_textures(&nfo);
	blit_image(&nfo);
	mlx_loop(nfo.mlx);
	array_str_free(nfo.map->grid, array_str_len(nfo.map->grid));
	system("leaks ./so_long");
	return (0);
}
