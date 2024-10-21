/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:30:49 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/21 13:36:42 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	validate_walls(t_args *args)
{
	t_position	pos;

	pos.y = 0;
	while (pos.y < args->map.dimensions.y)
	{
		if (pos.y == 0 || pos.y == args->map.dimensions.y - 1)
		{
			pos.x = 0;
			while (pos.x < args->map.dimensions.x)
			{
				if (args->map.grid[pos.y][pos.x] != WALL)
					ft_terminate(args, SURROUND_WALLS);
				pos.x++;
			}
		}
		else
		{
			if (args->map.grid[pos.y][0] != WALL)
				ft_terminate(args, SURROUND_WALLS);
			if (args->map.grid[pos.y][args->map.dimensions.x - 1] != WALL)
				ft_terminate(args, SURROUND_WALLS);
		}
		pos.y++;
	}
}

void	flood_map(t_map map, t_position pos)
{
	if (pos.x < 0 || pos.x >= map.dimensions.x)
		return ;
	if (pos.y < 0 || pos.y >= map.dimensions.y)
		return ;
	if (map.grid[pos.y][pos.x] == WALL || map.grid[pos.y][pos.x] == FILL)
		return ;
	map.grid[pos.y][pos.x] = FILL;
	flood_map(map, set_position(pos.x + 1, pos.y));
	flood_map(map, set_position(pos.x - 1, pos.y));
	flood_map(map, set_position(pos.x, pos.y + 1));
	flood_map(map, set_position(pos.x, pos.y - 1));
}

t_map	duplicate_map(t_args *args)
{
	t_map		dup;
	t_position	pos;

	dup = args->map;
	dup.grid = ft_calloc(dup.dimensions.y, sizeof(t_tile *));
	if (!dup.grid)
		ft_terminate(args, MALLOC_ERROR);
	pos.y = -1;
	while (++pos.y < dup.dimensions.y)
	{
		pos.x = -1;
		dup.grid[pos.y] = ft_calloc(dup.dimensions.x, sizeof(t_tile));
		if (!dup.grid[pos.y])
		{
			while (--pos.y > 0)
				free(dup.grid[pos.y]);
			free(dup.grid);
			ft_terminate(args, MALLOC_ERROR);
		}
		while (++pos.x < dup.dimensions.x)
			dup.grid[pos.y][pos.x] = args->map.grid[pos.y][pos.x];
	}
	return (dup);
}

void	validate_path(t_args *args)
{
	t_map		map;
	int			index;
	t_position	pos;
	bool		check;

	map = duplicate_map(args);
	flood_map(map, args->map.player.pos[0]);
	index = -1;
	check = true;
	while (++index < args->map.coin.quantity)
	{
		pos = args->map.coin.pos[index];
		if (map.grid[pos.y][pos.x] != FILL)
			check = false;
	}
	pos = args->map.exit.pos[0];
	if (map.grid[pos.y][pos.x] != FILL)
		check = false;
	index = -1;
	while (++index < map.dimensions.y)
		free(map.grid[index]);
	free(map.grid);
	if (!check)
		ft_terminate(args, NO_PATH);
}

void	validate_characters(t_args *args)
{
	int	index;

	index = 0;
	while (args->buffer[index])
	{
		if (args->buffer[index] != '\n' && args->buffer[index] != '1'
			&& args->buffer[index] != '0')
			ft_terminate(args, INVALID_CHAR);
		index++;
	}
}
