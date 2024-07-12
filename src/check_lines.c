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

int	line_len(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0' && s[i] != '\n')
	{
		i++;
	}
	return (i);
}

int	check_lines(t_nfo *nfo, char *path)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(path, O_RDWR);
	if (fd < 0)
		return (1);
	line = "";
	i = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			nfo->map->width = line_len(line);
			if (check_map_line(nfo, line, i) == 1)
				return (free(line), 1);
			free(line);
			i++;
		}
	}
	close(fd);
	nfo->map->height = i;
	return (0);
}

int	check_map_line(t_nfo *nfo, char *map_line, int line_id)
{
	int	i;

	if (map_line[0] == '\n')
		return (ft_putstr_fd(ERR_MAP0, 2), 1);
	if (map_line[0] != '1' || map_line[line_len(map_line) - 1] != '1')
		return (ft_putstr_fd(ERR_MAP5, 2), 1);
	i = 0;
	while (map_line[i] != '\n' && map_line[i] != '\0')
	{
		if (map_line[i] == 'C')
			nfo->map->nb_collectibles++;
		else if (map_line[i] == 'E')
			set_exit_nfo(nfo, i, line_id);
		else if (map_line[i] == 'P')
			set_player_nfo(nfo, i, line_id);
		else if (map_line[i] != '0' && map_line[i] != '1')
			return (ft_putstr_fd(ERR_MAP6, 2), 1);
		i++;
	}
	return (0);
}

void	set_exit_nfo(t_nfo *nfo, int x, int y)
{
	nfo->map->nb_exit++;
	nfo->map->exit_x = x;
	nfo->map->exit_y = y;
}

void	set_player_nfo(t_nfo *nfo, int x, int y)
{
	nfo->map->nb_player_start++;
	nfo->map->start_x = x;
	nfo->map->start_y = y;
	nfo->hero->x = x;
	nfo->hero->y = y;
	nfo->hero->nb_collected = 0;
}
