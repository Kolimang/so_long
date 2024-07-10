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

int	main(int argc, char *argv[])
{
	t_nfo		nfo;
	t_map		map;
	t_player	hero;

	init_structures(&nfo, &map, &hero);
	if (!is_map_valid(&nfo, argc, argv))
		return (1);
	create_grid(&nfo, argv[1], 0);
	nfo.mlx = mlx_init();
	if (!nfo.mlx)
		return (1);
	create_window(&nfo);
	if (!nfo.windw)
		return (free_all(&nfo), 1);
	mlx_hook(nfo.windw, ON_KEYRELEASE, 0, &on_keypress, &nfo);
	mlx_hook(nfo.windw, ON_DESTROY, 0, &on_destroy, &nfo);
	load_textures(&nfo);
	blit_image(&nfo);
	mlx_loop(nfo.mlx);
	free_all(&nfo);
	ft_printf("Ho Ho Ho !\n");
	return (system("leaks ./so_long"), 0);
}

void	free_all(t_nfo *nfo)
{
	array_str_free(nfo->map->grid, array_str_len(nfo->map->grid));
	free(nfo->mlx);
}
