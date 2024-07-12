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
	nfo->map->width = 0;
	nfo->map->height = 0;
	return (0);
}

void	load_textures(t_nfo *nfo)
{
	int	size;

	size = TIL_SZ;
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
