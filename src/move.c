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

void	handle_reached_item(t_nfo *nfo, int x, int y)
{
	nfo->hero->nb_collected++;
	put_img_2_window(nfo, 0, x, y);
	if (nfo->hero->nb_collected == nfo->map->nb_collectibles)
		put_img_2_window(nfo, 2, nfo->map->exit_x, nfo->map->exit_y);
}

void	handle_reached_exit(t_nfo *nfo)
{
	if (nfo->hero->nb_collected == nfo->map->nb_collectibles)
	{
		ft_printf("- - - - -\n");
		ft_printf("Well done! ");
		ft_printf("You exited the level in %d moves.\n", nfo->hero->moves);
		ft_printf("~~ The End ~~\n");
		on_destroy(nfo);
	}
}

void	update_player_position(t_nfo *nfo, int d, int x, int y)
{
	put_img_2_window(nfo, d, x, y);
	nfo->hero->x = x;
	nfo->hero->y = y;
}

void	move(t_nfo *nfo, int new_x, int new_y, int d)
{
	int	x;
	int	y;

	x = nfo->hero->x;
	y = nfo->hero->y;
	new_x += nfo->hero->x;
	new_y += nfo->hero->y;
	if (nfo->map->grid[new_y][new_x] == '1')
		return ;
	nfo->hero->moves++;
	if (nfo->hero->moves < 0)
		on_destroy(nfo);
	ft_printf("moves: %d\n", nfo->hero->moves);
	if (nfo->map->grid[new_y][new_x] == 'C')
		handle_reached_item(nfo, new_x, new_y);
	else if (nfo->map->grid[new_y][new_x] == 'E')
		handle_reached_exit(nfo);
	if (nfo->map->grid[new_y][new_x] != 'E')
		nfo->map->grid[new_y][new_x] = 'P';
	if (nfo->map->grid[y][x] != 'E')
		reset_grass(nfo, x, y);
	else
		put_img_2_window(nfo, 3, x, y);
	update_player_position(nfo, d, new_x, new_y);
}

/*
			  ^
			  |
			key 126
<-- key 123			key 124 -->
			key 125
			  |
			  v
*/
int	on_keypress(int key, t_nfo *nfo)
{
	if (key == 0 || key == 12 || key == 123)
		move(nfo, -1, 0, 6);
	else if (key == 2 || key == 124)
		move(nfo, 1, 0, 5);
	else if (key == 1 || key == 125)
		move(nfo, 0, 1, 7);
	else if (key == 6 || key == 13 || key == 126)
		move(nfo, 0, -1, 8);
	else if (key == 53)
	{
		ft_printf("You quit by pressing ESC.\n");
		on_destroy(nfo);
	}
	return (0);
}
