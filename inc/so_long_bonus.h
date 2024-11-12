/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:20:10 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/12 11:09:26 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft.h"
# include <MLX42/MLX42.h>
# include <fcntl.h>

# define ASSET_SIZE 64

typedef enum e_term_code
{
	OK,
	MALLOC_ERROR,
	OPEN_ERROR,
	WRONG_EXTENSION,
	MAP_NOT_RECTANGLE,
	INVALID_CHAR,
	COIN_QUANTITY,
	PLAYER_QUANTITY,
	EXIT_QUANTITY,
	SURROUND_WALLS,
	NO_PATH,
	MLX_ERROR,
	TEXTURE_ERROR,
	DEAD,
	ARG_NUMBER,
}	t_term_code;

typedef struct s_position
{
	int	x;
	int	y;	
}		t_position;

typedef struct s_obj
{
	int			quantity;
	int			collected;
	t_position	*pos;
}				t_obj;

typedef enum e_tile
{
	AIR,
	WALL,
	FILL,
}	t_tile;

typedef struct s_map
{
	t_position	dimensions;
	t_tile		**grid;
	t_obj		coin;
	t_obj		player;
	t_obj		exit;
	t_obj		enemy;
}				t_map;

typedef struct s_imgbundle
{
	mlx_image_t	*ground;
	mlx_image_t	*wall;
	mlx_image_t	*coin;
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*enemy;
	mlx_image_t	*moves;
}				t_imgbundle;

typedef struct s_args
{
	mlx_t		*mlx;
	t_map		map;
	t_imgbundle	images;
	int			moves;
	char		*buffer;
}			t_args;

void		ft_terminate(t_args *args, t_term_code type);
void		create_map(t_args *args, const char *pathfile);
void		read_file(t_args *args, int fd);
void		finish_file(int fd);
t_position	set_position(int x, int y);
void		validate_walls(t_args *args);
void		validate_path(t_args *args);
void		create_mlx(t_args *args);
void		key_manager(mlx_key_data_t keydata, void *param);
void		validate_characters(t_args *args);
void		parse_buffer(t_args *args);
void		update_move_img(t_args *args);

#endif
