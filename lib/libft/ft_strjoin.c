/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:26:27 by jeperez-          #+#    #+#             */
/*   Updated: 2024/09/16 18:44:04 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*value;
	int		s1_index;
	int		s2_index;

	value = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!value)
		return (0);
	s1_index = 0;
	while (s1[s1_index])
	{
		value[s1_index] = s1[s1_index];
		s1_index++;
	}
	s2_index = 0;
	while (s2[s2_index])
	{
		value[s1_index + s2_index] = s2[s2_index];
		s2_index++;
	}
	value[s1_index + s2_index] = 0;
	return (value);
}
