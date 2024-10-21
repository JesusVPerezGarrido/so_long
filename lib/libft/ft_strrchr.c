/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:11:49 by jeperez-          #+#    #+#             */
/*   Updated: 2024/09/19 10:04:53 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = ft_strlen(s);
	if (c == 0)
		return (((char *)s) + index);
	while (c > 256)
		c -= 256;
	while (index)
	{
		if (s[index - 1] == c)
			return (((char *)s) + index - 1);
		index--;
	}
	return (0);
}
