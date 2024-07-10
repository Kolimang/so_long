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
	if (check_input(argc, argv) == 1)
		return (0);
	if (check_lines(nfo, argv[1]) == 1)
		return (0);
	create_grid(nfo, argv[1], 0);
	if (check_grid(nfo) == 1)
	{
		array_str_free(nfo->map->grid, array_str_len(nfo->map->grid));
		return (0);
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
