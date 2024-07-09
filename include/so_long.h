/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:33:37 by jrichir           #+#    #+#             */
/*   Updated: 2024/07/04 19:12:53 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <libftx/libft.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
//#include <stdio.h>
//# include <string.h>

# define TILE_SZ 32
# define GM_NAME "A walk in the park"

# define TXPLAYER_R    "assets/hero_32_right.xpm"
# define TXPLAYER_L    "assets/hero_32_left.xpm"
# define TXPLAYER_D    "assets/hero_32_down.xpm"
# define TXPLAYER_U    "assets/hero_32_up.xpm"
# define TXGRASS       "assets/grass_32.xpm"
# define TXROCK        "assets/rock_32.xpm"
# define TXEXIT_C      "assets/exit_32_closed.xpm"
# define TXEXIT_O      "assets/exit_32_open.xpm"
# define TXCOLLECTIBLE "assets/collectible_32.xpm"

# define ERR_MAP0 "Error\nEmpty line in map.\n"
# define ERR_MAP1 "Error\nMap too large. Max 80 columns and 44 lines.\n"
# define ERR_MAP2 "Error\nThere must be at least 1 collectible (C).\n"
# define ERR_MAP3 "Error\nThere must be exactly 1 exit (E).\n"
# define ERR_MAP4 "Error\nThere must be exactly 1 start position (P).\n"
# define ERR_MAP5 "Error\nThere must be walls (1) all around the map.\n"
# define ERR_MAP6 "Error\nInvalid charachter in map.\n"
# define ERR_MAP7 "Error\nMap is not playable (no valid path).\n"

enum
{
	ON_KEYPRESS = 2,//   key press
	ON_KEYRELEASE = 3,//     key release
	ON_MOUSEPRESS = 4,// button press
	ON_MOUSERELEASE = 5,//   button release
	ON_MOUSEMOVE = 6,// motion
	ON_EXPOSE = 12,//   window visible
	ON_DESTROY = 17
};

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_map
{
	int		width;
	int		height;
	int		start_x;
	int		start_y;
	int		exit_x;
	int		exit_y;
	int		nb_collectibles;
	int		nb_collected;
	int		nb_player_start;
	int		nb_exit;
	int		valid;
	char	**grid;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	nb_collected;
	int	moves;
}	t_player;

typedef struct s_nfo
{
	int			winw;
	int			winh;
	void		*mlx; // MLX pointer
	void		*windw; // MLX window pointer
	void		*gfx[9]; // MLX image pointers (on the stack)
	t_map		*map; // Map pointer (contains map details pref.bly on stack)
	t_player	*hero;
}	t_nfo;

int		init_structures(t_nfo *nfo, t_map *map, t_player *hero);
int		line_len(char *s);
int		check_input(int argc, char **argv);
int		check_lines(t_nfo *nfo, char *path);
int		check_map_line(t_nfo *nfo, char *map_line, int line_id);
int		create_grid(t_nfo *nfo, char *path);
int		check_grid(t_nfo *nfo);
int		is_playable(t_nfo *nfo);
void	load_textures(t_nfo *nfo);
void	array_str_print(char **array, char separator);
int		array_str_len(char **array);
void	array_str_free(char **array, int limit);
int		is_wall(char *horiz_edge);
int		floodfill4(t_nfo *nfo, int x, int y);
int		is_fully_flooded(t_nfo *nfo);
void 	move(t_nfo *nfo, int new_x, int new_y, int d);

// typedef struct s_nfo
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }			t_nfo;

#endif
