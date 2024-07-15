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

int	is_wall(char *horiz_edge)
{
	if (!horiz_edge)
		return (0);
	while (*horiz_edge)
	{
		if (*horiz_edge != '1')
			return (0);
		horiz_edge++;
	}
	return (1);
}

int	is_playable(t_nfo *nfo)
{
	nfo->map->nb_collected = 0;
	floodfill4(nfo, nfo->map->start_x, nfo->map->start_y);
	return (is_fully_flooded(nfo));
}

int	is_fully_flooded(t_nfo *nfo)
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
			c = nfo->map->grid[y][x];
			if (c != '1' && c != '0')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	is_rectangular(t_nfo *nfo)
{
	int	i;

	i = 0;
	while (i < nfo->map->height)
	{
		if ((int)ft_strlen(nfo->map->grid[i]) != nfo->map->width)
			return (0);
		i++;
	}
	return (1);
}
