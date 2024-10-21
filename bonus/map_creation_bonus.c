/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:28:47 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/21 14:09:02 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	read_file(t_args *args, int fd)
{
	char	*line;
	int		line_length;

	args->buffer = ft_calloc(1, 1);
	line = get_next_line(fd);
	while (line)
	{
		args->map.dimensions.y++;
		line_length = ft_strlen(line);
		args->buffer = ft_freejoin(args->buffer, line);
		if (ft_strchr(line, '\n'))
			line_length--;
		free(line);
		if (!args->map.dimensions.x)
			args->map.dimensions.x = line_length;
		else if (args->map.dimensions.x != line_length)
		{
			finish_file(fd);
			ft_terminate(args, MAP_NOT_RECTANGLE);
		}
		line = get_next_line(fd);
	}
}

void	create_map(t_args *args, const char *pathfile)
{
	int		fd;
	char	*extension;

	extension = ft_strrchr(pathfile, '.');
	if (!extension || ft_strncmp(extension, ".ber", 5))
		ft_terminate(args, WRONG_EXTENSION);
	fd = open(pathfile, O_RDONLY);
	if (fd == -1)
		ft_terminate(args, OPEN_ERROR);
	read_file(args, fd);
	close(fd);
	parse_buffer(args);
	validate_walls(args);
	validate_path(args);
}
