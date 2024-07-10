/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:16:19 by jrichir           #+#    #+#             */
/*   Updated: 2024/07/05 10:39:16 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	floodfill4(t_nfo *nfo, int x, int y)
{
	if (x >= 0 && x < nfo->map->width && y >= 0 && y < nfo->map->height)
	{
		if (nfo->map->grid[y][x] != '1')
		{
			nfo->map->grid[y][x] = '1';
			floodfill4(nfo, x, y - 1);
			floodfill4(nfo, x, y + 1);
			floodfill4(nfo, x - 1, y);
			floodfill4(nfo, x + 1, y);
		}
	}
	return (0);
}
