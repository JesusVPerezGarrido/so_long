/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:34:58 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/18 12:32:18 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_line(t_args *args, int line, char *str)
{
	int	index;

	args->map.grid[line] = ft_calloc(args->map.dimensions.x, sizeof(t_tile));
	if (!args->map.grid[line])
	{
		free(str);
		ft_terminate(args, MALLOC_ERROR);
	}
	index = 0;
	while (str[index])
	{
		if (str[index] == '1')
			args->map.grid[line][index] = WALL;
		index++;
	}
}

void	parse_grid(t_args *args)
{
	int		index;
	int		start;
	int		length;
	char	*line;

	args->map.grid = ft_calloc(args->map.dimensions.y, sizeof(t_tile *));
	if (!args->map.grid)
		ft_terminate(args, MALLOC_ERROR);
	index = 0;
	start = 0;
	while (index < args->map.dimensions.y)
	{
		line = ft_strchr(args->buffer + start, '\n');
		if (line)
			length = line - args->buffer - start;
		else
			length = ft_strlen(args->buffer + start);
		line = ft_substr(args->buffer, start, length);
		start += length + 1;
		parse_line(args, index, line);
		free(line);
		index++;
	}
}

void	parse_obj(t_args *args, t_obj *obj, char o_char)
{
	int			index;
	t_position	pos;
	int			count;

	obj->pos = ft_calloc(obj->quantity, sizeof(t_position));
	if (!obj->pos)
		ft_terminate(args, MALLOC_ERROR);
	index = -1;
	pos = set_position(0, 0);
	count = 0;
	while (args->buffer[++index])
	{
		if (args->buffer[index] != '\n')
		{
			if (args->buffer[index] == o_char)
			{
				obj->pos[count++] = pos;
				args->buffer[index] = '0';
			}
			pos = set_position(pos.x + 1, pos.y);
		}
		else
			pos = set_position(0, pos.y + 1);
	}
}

void	parse_buffer(t_args *args)
{
	int	index;

	index = 0;
	parse_grid(args);
	args->map.coin.quantity = ft_charcount(args->buffer, 'C');
	if (args->map.coin.quantity == 0)
		ft_terminate(args, COIN_QUANTITY);
	args->map.player.quantity = ft_charcount(args->buffer, 'P');
	if (args->map.player.quantity > 1)
		ft_terminate(args, PLAYER_QUANTITY);
	args->map.exit.quantity = ft_charcount(args->buffer, 'E');
	if (args->map.exit.quantity > 1)
		ft_terminate(args, EXIT_QUANTITY);
	parse_obj(args, &(args->map.coin), 'C');
	parse_obj(args, &(args->map.player), 'P');
	parse_obj(args, &(args->map.exit), 'E');
	while (args->buffer[index])
	{
		if (args->buffer[index] != '\n' && args->buffer[index] != '1'
			&& args->buffer[index] != '0')
			ft_terminate(args, INVALID_CHAR);
		index++;
	}
	free(args->buffer);
	args->buffer = 0;
}

void	create_map(t_args *args, const char *pathfile)
{
	int		fd;

	if (ft_strncmp(ft_strrchr(pathfile, '.'), ".ber", 5))
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
