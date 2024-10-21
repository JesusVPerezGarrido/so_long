/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:18:46 by jeperez-          #+#    #+#             */
/*   Updated: 2024/09/18 13:25:42 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				index;
	unsigned char	c1;
	unsigned char	c2;

	index = 0;
	while (n)
	{
		c1 = ((unsigned char *)s1)[index];
		c2 = ((unsigned char *)s2)[index];
		if (c1 != c2)
			return (c1 - c2);
		index++;
		n--;
	}
	return (0);
}
