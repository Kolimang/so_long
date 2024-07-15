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

int	create_window(t_nfo *nfo)
{
	nfo->winw = nfo->map->width * TIL_SZ;
	nfo->winh = nfo->map->height * TIL_SZ;
	nfo->windw = mlx_new_window(nfo->mlx, nfo->winw, nfo->winh, GM_NAME);
	if (!(nfo->windw))
		return (1);
	return (0);
}

int	put_img_2_window(t_nfo *nfo, int gfxid, int x, int y)
{
	mlx_put_image_to_window(nfo->mlx, nfo->windw, nfo->gfx[gfxid],
		TIL_SZ * x, TIL_SZ * y);
	return (0);
}

void	blit_map(t_nfo *nfo)
{
	int		x;
	int		y;

	if (!nfo)
		return ;
	y = 0;
	while (y < nfo->map->height)
	{
		x = 0;
		while (x < nfo->map->width)
		{
			put_img_2_window(nfo, 0, x, y);
			if (nfo->map->grid[y][x] == '1')
				put_img_2_window(nfo, 1, x, y);
			else if (nfo->map->grid[y][x] == 'E')
				put_img_2_window(nfo, 3, x, y);
			else if (nfo->map->grid[y][x] == 'C')
				put_img_2_window(nfo, 4, x, y);
			else if (nfo->map->grid[y][x] == 'P')
				put_img_2_window(nfo, 7, x, y);
			x++;
		}
		y++;
	}
}

void	reset_grass(t_nfo *nfo, int x, int y)
{
	nfo->map->grid[y][x] = '0';
	put_img_2_window(nfo, 0, x, y);
}
