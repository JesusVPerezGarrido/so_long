/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:56:38 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/21 13:52:03 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_objs(t_args *args)
{
	t_position	player;
	int			index;

	player = args->map.player.pos[0];
	index = -1;
	while (++index < args->map.coin.quantity)
	{
		if (args->map.coin.pos[index].y == player.y
			&& args->map.coin.pos[index].x == player.x)
		{
			args->map.coin.pos[index] = set_position(0, 0);
			args->map.coin.collected++;
			args->images.coin->instances[index].enabled = false;
		}
	}
	if (args->map.exit.pos[0].y == player.y
		&& args->map.exit.pos[0].x == player.x
		&& args->map.coin.collected == args->map.coin.quantity)
		ft_terminate(args, OK);
}

void	sl_move(t_args *args, t_position move)
{
	t_position	player;

	player = args->map.player.pos[0];
	if (args->map.grid[player.y + move.y][player.x + move.x] != WALL)
	{
		args->moves++;
		ft_printf("moves: %i\n", args->moves);
		args->map.player.pos[0] = set_position(player.x + move.x,
				player.y + move.y);
		args->images.player->instances[0].x += move.x * ASSET_SIZE;
		args->images.player->instances[0].y += move.y * ASSET_SIZE;
		check_objs(args);
	}
}

void	key_manager(mlx_key_data_t keydata, void *param)
{
	t_args	*args;

	args = param;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_RELEASE)
		sl_move(args, set_position(0, -1));
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_RELEASE)
		sl_move(args, set_position(-1, 0));
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_RELEASE)
		sl_move(args, set_position(0, 1));
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_RELEASE)
		sl_move(args, set_position(1, 0));
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		ft_terminate(args, OK);
}
