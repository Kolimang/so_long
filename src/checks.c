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

int	check_input(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./so_long maps/MAP_NAME.ber\n", 2);
		return (1);
	}
	else
	{
		fd = open(argv[1], O_RDWR);
		if (!fd || fd < 0)
		{
			ft_putstr_fd("Invalid map name/path.\n", 2);
			return (1);
		}
		close(fd);
	}
	return (0);
}

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

int	check_lines(t_data *data, char *path)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(path, O_RDWR);
	line = "";
	i = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			data->map->width = line_len(line);
			if (check_map_line(data, line, i) == 1)
				return (free(line), 1);
			free(line);
			i++;
		}
	}
	close(fd);
	data->map->height = i;
	return (0);
}

int	create_grid(t_data *data, char *path)
{
	int		fd;
	int		i;
	char	*line;

	data->map->grid = malloc((data->map->height + 1) * sizeof(char *));
	if (!data->map->grid)
		return (1);
	data->map->grid[data->map->height] = NULL;
	fd = open(path, O_RDWR);
	line = "";
	i = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			data->map->grid[i] = malloc((line_len(line) + 1) * sizeof(char));
			if (!data->map->grid[i])
				return (1);
			ft_strlcpy(data->map->grid[i], (const char *)line, line_len(line) + 1);
			data->map->grid[i][line_len(line)] = '\0';
			i++;
			free(line);
		}
	}
	close(fd);
	return (0);
}

int	is_wall(char *horiz_edge)
{
	if (!horiz_edge)
		return (-1);
	while (*horiz_edge)
	{
		if (*horiz_edge != '1')
			return (0);
		horiz_edge++;
	}
	return (1);
}

int	floodfill4(t_data *data, int x, int y)
{
	if (x >= 0 && x < data->map->width && y >= 0 && y < data->map->height)
	{
		if (data->map->grid[y][x] != '1')
		{
			data->map->grid[y][x] = '1';
			floodfill4(data, x, y - 1);
			floodfill4(data, x, y + 1);
			floodfill4(data, x - 1, y);
			floodfill4(data, x + 1, y);
		}
	}
	return (0);
}

int	is_playable(t_data *data)
{
	data->map->nb_collected = 0;
	floodfill4(data, data->map->start_x, data->map->start_y);
	return (is_fully_flooded(data));
}

int	is_fully_flooded(t_data *data)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			c = data->map->grid[y][x];
			if (c != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_grid(t_data *data)
{
	if (data->map->height > 44 || data->map->width > 80)
		return (ft_putstr_fd(ERR_MAP1, 2), 1);
	else if (data->map->nb_collectibles < 1)
		return (ft_putstr_fd(ERR_MAP2, 2), 1);
	else if (data->map->nb_exit != 1)
		return (ft_putstr_fd(ERR_MAP3, 2), 1);
	else if (data->map->nb_player_start != 1)
		return (ft_putstr_fd(ERR_MAP4, 2), 1);
	else if (!is_wall(data->map->grid[0]) || !is_wall(data->map->grid[data->map->height - 1]))
		return (ft_putstr_fd(ERR_MAP5, 2), 1);
	else if (!is_playable(data))
		return (ft_putstr_fd(ERR_MAP7, 2), 1);
	return (0);
}

void	array_str_print(char **array, char separator)
{
	int	i;

	if (!array)
		return ;
	i = -1;
	while (array[++i])
	{
		ft_printf("%s%c", array[i], separator);
	}
	ft_printf("\n");
}

int	check_map_line(t_data *data, char *map_line, int line_id)
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
			data->map->nb_collectibles++;
		else if (map_line[i] == 'E')
		{
			data->map->nb_exit++;
			data->map->exit_x = i;
			data->map->exit_y = line_id;
		}
		else if (map_line[i] == 'P')
		{
			data->map->nb_player_start++;
			data->map->start_x = i;
			data->map->start_y = line_id;
		}
		else if (map_line[i] != '0' && map_line[i] != '1')
			return (ft_putstr_fd(ERR_MAP6, 2), 1);
		i++;
	}
	return (0);
}
