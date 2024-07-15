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

int	is_valid_path(int argc, char **argv)
{
	int		fd;
	int		comp;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./so_long maps/MAP_NAME.ber\n", 2);
		return (0);
	}
	comp = ft_strncmp(".ber", &argv[1][ft_strlen(argv[1]) - 4], 4);
	if (comp)
	{
		ft_putstr_fd("Map must have a \".ber\" file extension.\n", 2);
		return (0);
	}
	fd = open(argv[1], O_RDWR);
	if (!fd || fd < 0)
	{
		ft_putstr_fd("Invalid map name/path.\n", 2);
		return (0);
	}
	close(fd);
	return (1);
}
