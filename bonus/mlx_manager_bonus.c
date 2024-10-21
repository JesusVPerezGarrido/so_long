/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:57:32 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/21 14:35:48 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

mlx_image_t	*load_image(t_args *args, char *texturepath)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(texturepath);
	if (!texture)
		ft_terminate(args, TEXTURE_ERROR);
	image = mlx_texture_to_image(args->mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		ft_terminate(args, TEXTURE_ERROR);
	return (image);
}

void	draw_grid(t_args *args)
{
	t_position	pos;

	pos.y = -1;
	while (++pos.y < args->map.dimensions.y)
	{
		pos.x = -1;
		while (++pos.x < args->map.dimensions.x)
		{
			mlx_image_to_window(args->mlx, args->images.ground,
				pos.x * ASSET_SIZE, pos.y * ASSET_SIZE);
			if (args->map.grid[pos.y][pos.x] == WALL)
				mlx_image_to_window(args->mlx, args->images.wall,
					pos.x * ASSET_SIZE, pos.y * ASSET_SIZE);
		}
	}
}

void	draw_objs(t_args *args)
{
	int	index;

	index = -1;
	while (++index < args->map.coin.quantity)
	{
		mlx_image_to_window(args->mlx, args->images.coin,
			args->map.coin.pos[index].x * ASSET_SIZE,
			args->map.coin.pos[index].y * ASSET_SIZE);
	}
	index = -1;
	while (++index < args->map.enemy.quantity)
	{
		mlx_image_to_window(args->mlx, args->images.enemy,
			args->map.enemy.pos[index].x * ASSET_SIZE,
			args->map.enemy.pos[index].y * ASSET_SIZE);
	}
	mlx_image_to_window(args->mlx, args->images.exit,
		args->map.exit.pos[0].x * ASSET_SIZE,
		args->map.exit.pos[0].y * ASSET_SIZE);
	mlx_image_to_window(args->mlx, args->images.player,
		args->map.player.pos[0].x * ASSET_SIZE,
		args->map.player.pos[0].y * ASSET_SIZE);
}

void	create_mlx(t_args *args)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	args->mlx = mlx_init(args->map.dimensions.x * ASSET_SIZE,
			args->map.dimensions.y * ASSET_SIZE, "so_loooooooooooooong", true);
	if (!args->mlx)
		ft_terminate(args, MLX_ERROR);
	args->images.ground = load_image(args, "assets/ground.png");
	args->images.wall = load_image(args, "assets/wall.png");
	args->images.coin = load_image(args, "assets/coin.png");
	args->images.player = load_image(args, "assets/player.png");
	args->images.exit = load_image(args, "assets/exit.png");
	args->images.enemy = load_image(args, "assets/enemy.png");
	draw_grid(args);
	draw_objs(args);
	update_move_img(args);
	mlx_key_hook(args->mlx, key_manager, args);
}
