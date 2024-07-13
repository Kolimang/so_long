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

int	create_grid(t_nfo *nfo, char *path, int i)
{
	int		fd;
	char	*ln;

	nfo->map->grid = malloc((nfo->map->height + 1) * sizeof(char *));
	fd = open(path, O_RDWR);
	if (!nfo->map->grid || fd < 0)
		return (1);
	nfo->map->grid[nfo->map->height] = NULL;
	ln = "";
	while (ln)
	{
		//ln = get_next_line(fd);
		//if (ln)
		if (ln = get_next_line(fd))
		{
			nfo->map->grid[i] = malloc((line_len(ln) + 1) * sizeof(char));
			if (!nfo->map->grid[i])
			{
				close(fd);
				return (free(ln), array_str_free(nfo->map->grid, i), 1);
			}
			ft_strlcpy(nfo->map->grid[i], (const char *)ln, line_len(ln) + 1);
			//nfo->map->grid[i][line_len(ln)] = '\0';
			i++;
			free(ln);
		}
	}
	close(fd);
	return (0);
}

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

int	check_grid(t_nfo *nfo)
{
	if (nfo->map->height > 44 || nfo->map->width > 80)
		return (ft_putstr_fd(ERR_MAP1, 2), 1);
	else if (nfo->map->nb_collectibles < 1)
		return (ft_putstr_fd(ERR_MAP2, 2), 1);
	else if (nfo->map->nb_exit != 1)
		return (ft_putstr_fd(ERR_MAP3, 2), 1);
	else if (nfo->map->nb_player_start != 1)
		return (ft_putstr_fd(ERR_MAP4, 2), 1);
	else if (!is_wall(nfo->map->grid[0]))
		return (ft_putstr_fd(ERR_MAP5, 2), 1);
	else if (!is_wall(nfo->map->grid[nfo->map->height - 1]))
		return (ft_putstr_fd(ERR_MAP5, 2), 1);
	else if (!is_playable(nfo))
		return (ft_putstr_fd(ERR_MAP7, 2), 1);
	else if (!is_rectangular(nfo))
		return (ft_putstr_fd(ERR_MAP8, 2), 1);
	return (0);
}
