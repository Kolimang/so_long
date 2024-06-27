/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:33:37 by jrichir           #+#    #+#             */
/*   Updated: 2024/06/27 12:45:40 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define GL_SILENCE_DEPRECATION // does not seem to work

# include <libftx/libft.h>
# include <mlx.h>
//# include <unistd.h>
//# include <stdlib.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

//# define EXIT_ERROR_USAGE "Usage : ./client [server_id] [string]\n"

//void	send_string(int process, char *string);
//void	send_byte(int process, char byte);
//void	send_32int(int process, int nb);

#endif
