/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:12:18 by jeperez-          #+#    #+#             */
/*   Updated: 2024/09/19 10:04:35 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		index;
	char	mem_c;

	while (c > 256)
		c -= 256;
	index = 0;
	while (n)
	{
		mem_c = ((unsigned char *)s)[index];
		if (mem_c == c)
			return (&(((unsigned char *)s)[index]));
		index++;
		n--;
	}
	return (0);
}
