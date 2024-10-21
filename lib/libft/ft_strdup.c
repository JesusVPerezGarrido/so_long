/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:38:57 by jeperez-          #+#    #+#             */
/*   Updated: 2024/09/12 11:37:12 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*value;
	int		index;

	value = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!value)
		return (0);
	index = 0;
	while (s[index])
	{
		value[index] = s[index];
		index++;
	}
	value[index] = 0;
	return (value);
}
