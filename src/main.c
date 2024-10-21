/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:18:08 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/18 13:49:05 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char**argv)
{
	t_args	*args;

	if (argc != 2)
		exit(1);
	args = ft_calloc(1, sizeof(t_args));
	if (!args)
		ft_terminate(args, MALLOC_ERROR);
	create_map(args, argv[1]);
	create_mlx(args);
	mlx_loop(args->mlx);
	ft_terminate(args, OK);
}
