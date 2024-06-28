/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:33:37 by jrichir           #+#    #+#             */
/*   Updated: 2024/06/28 12:03:00 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define GL_SILENCE_DEPRECATION

# include <libftx/libft.h>
# include <mlx.h>
//# include <unistd.h>
//# include <stdlib.h>

enum
{
	ON_KEYDOWN = 2, //   key press
	ON_KEYUP = 3, //     key release
	ON_MOUSEDOWN = 4, // button press
	ON_MOUSEUP = 5, //   button release
	ON_MOUSEMOVE = 6, // motion
	ON_EXPOSE = 12, //   window visible
	ON_DESTROY = 17
};

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

#endif
