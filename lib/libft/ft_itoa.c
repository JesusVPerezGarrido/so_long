/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:19:29 by jeperez-          #+#    #+#             */
/*   Updated: 2024/09/18 15:45:00 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_int_length(int nbr)
{
	int	value;

	value = 1;
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
	{
		nbr *= -1;
		value++;
	}
	if (nbr >= 10)
		value += get_int_length(nbr / 10);
	return (value);
}

static int	get_int_char(int nbr, int index)
{
	while (index - 1)
	{
		nbr /= 10;
		index--;
	}
	return ((nbr % 10) + 48);
}

static void	fill_itoa(char *s, int nbr, int length)
{
	int	index;

	index = 0;
	if (nbr == -2147483648)
	{
		s[0] = '-';
		s[1] = '2';
		nbr = 147483648;
		length -= 2;
		s += 2;
	}
	if (nbr < 0)
	{
		s[0] = '-';
		nbr *= -1;
		length--;
		s++;
	}
	while (index < length)
	{
		s[index] = get_int_char(nbr, length - index);
		index++;
	}
}

char	*ft_itoa(int n)
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
