/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:19:29 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/14 11:30:30 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_int_length(unsigned int nbr)
{
	int	value;

	value = 1;
	while (nbr >= 10)
	{
		value++;
		nbr /= 10;
	}
	return (value);
}

static int	get_int_char(unsigned int nbr, unsigned int index)
{
	while (index - 1)
	{
		nbr /= 10;
		index--;
	}
	return ((nbr % 10) + 48);
}

static void	fill_itoa(char *s, int nbr, unsigned int length)
{
	unsigned int	index;

	index = 0;
	while (index < length)
	{
		s[index] = get_int_char(nbr, length - index);
		index++;
	}
}

char	*ft_uitoa(unsigned int n)
{
	char	*value;
	int		length;

	length = get_int_length(n);
	value = ft_calloc(sizeof(char), length + 1);
	if (!value)
		return (0);
	fill_itoa(value, n, length);
	return (value);
}
