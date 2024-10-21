/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:55:39 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/14 11:30:30 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhex(int hex, int upp)
{
	char	*str;
	int		length;

	str = ft_hextoa(hex, upp);
	if (!str)
		return (-1);
	length = ft_printstr(str);
	free(str);
	return (length);
}
