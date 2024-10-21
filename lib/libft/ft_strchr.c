/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:04:08 by jeperez-          #+#    #+#             */
/*   Updated: 2024/09/19 10:04:45 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	index;

	if (c == 0)
		return (((char *)s) + ft_strlen(s));
	while (c > 256)
		c -= 256;
	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			return (((char *)s) + index);
		index++;
	}
	return (0);
}
