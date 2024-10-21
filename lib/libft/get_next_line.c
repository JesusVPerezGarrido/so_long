/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:55:55 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/14 11:30:57 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*gnl_reduce(char *buffer)
{
	int		index;
	int		v_index;
	char	*value;

	index = 0;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	if (!buffer[index])
	{
		free(buffer);
		return (0);
	}
	value = ft_calloc((ft_strlen(buffer) - index + 1), sizeof(char));
	index++;
	v_index = 0;
	while (buffer[index])
		value[v_index++] = buffer[index++];
	free(buffer);
	return (value);
}

static char	*gnl_line(char *buffer)
{
	char	*value;
	int		index;

	index = 0;
	if (!buffer[index])
		return (0);
	while (buffer[index] && buffer[index] != '\n')
		index++;
	value = ft_calloc(index + 2, sizeof(char));
	index = 0;
	while (buffer[index] && buffer[index] != '\n')
	{
		value[index] = buffer[index];
		index++;
	}
	if (buffer[index] && buffer[index] == '\n')
		value[index++] = '\n';
	return (value);
}

static void	swapfree(char **dst, void *src)
{
	free(*dst);
	*dst = src;
}

static char	*gnl_read(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(res);
			free(buffer);
			return (0);
		}
		buffer[byte_read] = 0;
		swapfree(&res, ft_strjoin(res, buffer));
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer[__FD_SETSIZE];
	char		*value;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer[fd])
			free(buffer[fd]);
		buffer[fd] = NULL;
		return (0);
	}
	buffer[fd] = gnl_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (0);
	value = gnl_line(buffer[fd]);
	buffer[fd] = gnl_reduce(buffer[fd]);
	return (value);
}
