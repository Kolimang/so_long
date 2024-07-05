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

#include <push_swap.h>

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

int	*array_atoi(char **array)
{
	int	i;
	int	*intarray;

	if (!array)
		return (NULL);
	intarray = (int *)malloc((array_str_len(array)) * sizeof(int));
	if (!intarray)
		return (NULL);
	i = -1;
	while (array[++i])
	{
		if (ft_streqint(array[i]) == -1)
		{
			free(intarray);
			return (NULL);
		}
		intarray[i] = ft_atoi(array[i]);
	}
	return (intarray);
}
