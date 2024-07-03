/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:33:37 by jrichir           #+#    #+#             */
/*   Updated: 2024/07/03 16:15:05 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <libftx/libft.h>
# include <mlx.h>
# include <stdlib.h>
//# include <string.h>
//# include <unistd.h>

# define TILE_SIZE 32
# define TXPLAYER "assets/player_32_right.xpm"
# define TXGRASS "assets/grass_32.xpm"
# define TXROCK "assets/rock_32.xpm"
# define TXEXIT "assets/exit_32_open.xpm"
# define TXCOLLECTIBLE "assets/collectible_32.xpm"

enum
{
	ON_KEYPRESS = 2, //   key press
	ON_KEYRELEASE = 3, //     key release
	ON_MOUSEPRESS = 4, // button press
	ON_MOUSERELEASE = 5, //   button release
	ON_MOUSEMOVE = 6, // motion
	ON_EXPOSE = 12, //   window visible
	ON_DESTROY = 17
};

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_map
{
	int	width;
	int	height;
	int	valid;
}	t_map;

typedef struct s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*textures[5]; // MLX image pointers (on the stack)
	t_map		*map; // Map pointer (contains map details pref.bly on stack)
}	t_data;

// typedef struct s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }			t_data;

#endif
