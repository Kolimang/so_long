/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_arrays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:07:08 by jrichir           #+#    #+#             */
/*   Updated: 2024/06/04 15:34:14 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	array_str_free(char **array, int limit)
{
	int	i;

	if (!array)
		return ;
	i = -1;
	while (++i < limit)
	{
		free(array[i]);
	}
	free(array);
}

int	array_str_len(char **array)
{
	int	i;

	if (!array)
		return (-1);
	i = 0;
	while (array[i] != NULL)
	{
		i++;
	}
	return (i);
}

