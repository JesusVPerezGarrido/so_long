/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:16:05 by jeperez-          #+#    #+#             */
/*   Updated: 2024/09/17 19:18:39 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	mem_c;

	if (dest == src)
		return (dest);
	while (n)
	{
		n--;
		mem_c = ((unsigned char *)src)[n];
		((unsigned char *)dest)[n] = mem_c;
	}
	return (dest);
}
