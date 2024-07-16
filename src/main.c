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
	if (!is_map_valid(&nfo, argc, argv) || create_grid(&nfo, argv[1], 0))
		return (1);
	nfo.mlx = mlx_init();
	if (!nfo.mlx)
		return (free_all(&nfo), 1);
	if (create_window(&nfo))
	{
		free_all(&nfo);
		return (1);
	}
	mlx_hook(nfo.windw, ON_KEYPRESS, 0, &on_keypress, &nfo);
	mlx_hook(nfo.windw, ON_DESTROY, 0, &on_destroy, &nfo);
	if (load_textures(&nfo))
		return (free_all(&nfo), 1);
	blit_map(&nfo);
	mlx_loop(nfo.mlx);
	free_all(&nfo);
	return (0);
}

void	free_all(t_nfo *nfo)
{
	array_str_free(nfo->map->grid, array_str_len(nfo->map->grid));
	if(nfo->mlx)
	{
		free(nfo->mlx);
		nfo->mlx = NULL;
	}
}

int	on_destroy(t_nfo *nfo)
{
	mlx_destroy_window(nfo->mlx, nfo->windw);
	free_all(nfo);
	exit(0);
}
