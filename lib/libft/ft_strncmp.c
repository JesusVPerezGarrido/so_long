/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:18:37 by jeperez-          #+#    #+#             */
/*   Updated: 2024/09/18 15:34:17 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	index;
	int	c1;
	int	c2;

	index = 0;
	while (n)
	{
		if (s1[index] == s2[index])
		{
			if (!s1[index])
				return (0);
			index++;
		}
		else
		{
			c1 = (unsigned char)s1[index];
			c2 = (unsigned char)s2[index];
			return (c1 - c2);
		}
		n--;
	}
	return (0);
}
