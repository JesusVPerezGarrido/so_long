/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:01:22 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/21 13:31:14 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_position	set_position(int x, int y)
{
	t_position	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}
