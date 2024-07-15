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

int	is_map_valid(t_nfo *nfo, int argc, char **argv)
{
	if (!is_valid_path(argc, argv))
		return (0);
	if (check_lines(nfo, argv[1]) || create_grid(nfo, argv[1], 0))
		return (0);
	if (check_grid(nfo) == 1)
	{
		array_str_free(nfo->map->grid, array_str_len(nfo->map->grid));
		return (0);
	}
	array_str_free(nfo->map->grid, array_str_len(nfo->map->grid));
	return (1);
}

int	alloc_grid(t_nfo *nfo)
{
	nfo->map->grid = malloc((nfo->map->height + 1) * sizeof(char *));
	if (!nfo->map->grid)
		return (1);
	nfo->map->grid[nfo->map->height] = NULL;
	return (0);
}

int	create_grid(t_nfo *nfo, char *path, int i)
{
	if (alloc_grid(nfo) || fill_grid(nfo, path, i))
		return (1);
	return (0);
}

int	fill_grid(t_nfo *nfo, char *path, int i)
{
	int		fd;
	char	*ln;

	fd = open(path, O_RDWR);
	if (fd < 0)
		return (1);
	ln = "";
	while (ln)
	{
		ln = get_next_line(fd);
		if (ln)
		{
			nfo->map->grid[i] = malloc((line_len(ln) + 1) * sizeof(char));
			if (!nfo->map->grid[i])
			{
				close(fd);
				return (free(ln), array_str_free(nfo->map->grid, i), 1);
			}
			ft_strlcpy(nfo->map->grid[i], (const char *)ln, line_len(ln) + 1);
			i++;
			free(ln);
		}
	}
	close(fd);
	return (0);
}
// right below the strlcpy : //nfo->map->grid[i][line_len(ln)] = '\0';

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
