/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:41:58 by jeperez-          #+#    #+#             */
/*   Updated: 2024/09/14 18:58:23 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	mem_c;
	size_t			index;

	if (dest == src)
		return (dest);
	if (dest > src)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		index = 0;
		while (index < n)
		{
			mem_c = ((unsigned char *)src)[index];
			((unsigned char *)dest)[index] = mem_c;
			index++;
		}
	}
	return (dest);
}
