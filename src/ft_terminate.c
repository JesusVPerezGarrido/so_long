/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:19:07 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/21 14:18:03 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish_file(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	ft_free_grid(t_map map)
{
	int	index;

	index = 0;
	while (index < map.dimensions.y)
	{
		free(map.grid[index]);
		index++;
	}
	free(map.grid);
}

void	ft_term_free(t_args *args)
{
	if (args)
	{
		if (args->mlx)
			mlx_terminate(args->mlx);
		if (args->buffer)
			free(args->buffer);
		if (args->map.grid)
			ft_free_grid(args->map);
		if (args->map.coin.pos)
			free(args->map.coin.pos);
		if (args->map.player.pos)
			free(args->map.player.pos);
		if (args->map.exit.pos)
			free(args->map.exit.pos);
		free(args);
	}
	exit(0);
}

void	ft_terminate_cont(t_term_code type)
{
	if (type == MLX_ERROR)
		ft_printf("Error opening window.\n");
	if (type == TEXTURE_ERROR)
		ft_printf("Error loading a texture.\n");
}

void	ft_terminate(t_args *args, t_term_code type)
{
	if (type >= MLX_ERROR)
		ft_terminate_cont(type);
	if (type == OK)
		ft_printf("Good bye. :D\n");
	if (type == MALLOC_ERROR)
		ft_printf("Error when allocating memory.\n");
	if (type == WRONG_EXTENSION)
		ft_printf("Error\nMap does not have correct extension.\n");
	if (type == OPEN_ERROR)
		ft_printf("Error when opening map.\n");
	if (type == MAP_NOT_RECTANGLE)
		ft_printf("Error\nWhat is a circle? do you eat it?.\n");
	if (type == INVALID_CHAR)
		ft_printf("Error\nThere's an invalid char among us.\n");
	if (type == COIN_QUANTITY)
		ft_printf("Error\nYou need more gold!\n");
	if (type == PLAYER_QUANTITY)
		ft_printf("Error\nThis is a single player game mate.\n");
	if (type == EXIT_QUANTITY)
		ft_printf("Error\nOpening multiple portals could destroy reality!\n");
	if (type == SURROUND_WALLS)
		ft_printf("Error\nTHE BOX HAS A HOLE!\n");
	if (type == NO_PATH)
		ft_printf("Error\nSorry, you can't walk through walls...\n");
	ft_term_free(args);
}
