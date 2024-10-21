/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:51:41 by jeperez-          #+#    #+#             */
/*   Updated: 2024/09/12 19:14:03 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*value;

	index = 0;
	value = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!value)
		return (0);
	while (s[index])
	{
		value[index] = (*f)(index, s[index]);
		index++;
	}
	return (value);
}
