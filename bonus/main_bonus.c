/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:18:08 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/21 17:05:51 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char**argv)
{
	t_args	*args;

	args = ft_calloc(1, sizeof(t_args));
	if (!args)
		ft_terminate(args, MALLOC_ERROR);
	if (argc != 2)
		ft_terminate(args, ARG_NUMBER);
	create_map(args, argv[1]);
	create_mlx(args);
	mlx_loop(args->mlx);
	ft_terminate(args, OK);
}
