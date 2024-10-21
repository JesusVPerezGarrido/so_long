/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:10:38 by jeperez-          #+#    #+#             */
/*   Updated: 2024/09/18 15:34:33 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	keep_lowest(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*value;
	int				index;
	unsigned int	sub_len;

	sub_len = ft_strlen(s);
	if (start > sub_len)
		return (ft_calloc(1, 1));
	sub_len = keep_lowest(sub_len - start, len);
	value = ft_calloc(sub_len + 1, sizeof(char));
	if (!value)
		return (0);
	index = 0;
	while (sub_len)
	{
		value[index] = s[start + index];
		index++;
		sub_len--;
	}
	value[index] = 0;
	return (value);
}
