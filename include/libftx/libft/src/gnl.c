/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:28:16 by jrichir           #+#    #+#             */
/*   Updated: 2024/07/04 18:36:53 by jrichir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	del(char **s1)
{
	free(*s1);
	*s1 = NULL;
	return (1);
}

static char	**split_at_nl(char **str, char **splitpos)
{
	char	**chunks;
	int		len;

	if (!str || !*str || !*splitpos || !splitpos)
		return (NULL);
	len = *splitpos - *str + 1;
	chunks = (char **)malloc(2 * sizeof(char *));
	if (!chunks)
		return (del(str), NULL);
	chunks[0] = malloc((1 + len) * sizeof(char));
	if (!chunks[0])
		return (del(str), free(chunks), NULL);
	chunks[1] = malloc((ft_gnl_strlen(*str) - len + 1) * sizeof(char));
	if (!chunks[1])
		return (del(str), del(&chunks[0]), free(chunks), NULL);
	ft_gnl_strlcpy(chunks[0], *str, len + 1);
	ft_gnl_strlcpy(chunks[1], *str + len, ft_gnl_strlen(*str) - len + 1);
	del(str);
	return (chunks);
}

static char	*process_line(char **stock)
{
	char	**chunks;
	char	*nl;
	char	*line;

	nl = ft_gnl_strchr(*stock, '\n');
	if (!nl)
	{
		line = ft_gnl_strdup(stock);
		if (line)
			del(stock);
		return (line);
	}
	chunks = split_at_nl(stock, &nl);
	if (!chunks)
		return (del(stock), NULL);
	if (chunks[1][0] != '\0')
	{
		*stock = ft_gnl_strdup(&chunks[1]);
		if (!stock)
			return (del(&chunks[0]), free(chunks), NULL);
	}
	line = ft_gnl_strdup(&chunks[0]);
	if (!line)
		return (del(stock), del(&chunks[1]), free(chunks), NULL);
	return (del(&chunks[0]), del(&chunks[1]), free(chunks), line);
}

char	*get_next_line(int fd)
{
	ssize_t		count;
	char		*rd_buf;
	static char	*stock[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || read(fd, 0, 0) < 0
		|| BUFFER_SIZE < 1 || BUFFER_SIZE >= 2147483647)
		return (del(&stock[fd]), NULL);
	rd_buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!rd_buf && del(&stock[fd]))
		return (NULL);
	while (!ft_gnl_strchr(stock[fd], '\n'))
	{
		count = read(fd, rd_buf, BUFFER_SIZE);
		if (count < 0 || (count == 0 && (!stock[fd] || stock[fd][0] == '\0')))
			return (del(&stock[fd]), del(&rd_buf), NULL);
		else if (count == 0 && stock[fd] && stock[fd][0] != '\0')
			break ;
		rd_buf[count] = '\0';
		stock[fd] = ft_gnl_strjoin(&stock[fd], &rd_buf, 2);
		if (!stock[fd])
			return (del(&rd_buf), NULL);
	}
	del(&rd_buf);
	return (process_line(&stock[fd]));
}
