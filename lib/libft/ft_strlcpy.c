/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:47:12 by jeperez-          #+#    #+#             */
/*   Updated: 2024/09/17 19:22:23 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t	index;

	index = 0;
	if (destsize == 0)
		return (ft_strlen(src));
	while (src[index] && destsize > index + 1)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = 0;
	return (ft_strlen(src));
}
