/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:37:38 by jeperez-          #+#    #+#             */
/*   Updated: 2024/09/19 14:57:15 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;
	size_t	b_index;

	l_len = ft_strlen(little);
	if (l_len == 0)
		return ((char *)big);
	b_index = 0;
	while (big[b_index] && (b_index + l_len) <= len)
	{
		if (!ft_strncmp(big + b_index, little, l_len))
			return (((char *)big) + b_index);
		b_index++;
	}
	return (0);
}
