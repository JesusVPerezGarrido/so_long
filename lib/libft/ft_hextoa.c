/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:00:01 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/14 11:30:30 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hex_len(unsigned int nbr)
{
	int	value;

	value = 1;
	while (nbr > 15)
	{
		nbr /= 16;
		value++;
	}
	return (value);
}

static void	fill_hex(char *str, unsigned int nbr, int len, int upp)
{
	char	*letters;
	int		index;

	if (upp)
		letters = ft_strdup("0123456789ABCDEF");
	else
		letters = ft_strdup("0123456789abcdef");
	index = -1;
	while (++index < len)
	{
		str[(len - index) - 1] = letters[nbr % 16];
		nbr /= 16;
	}
	free(letters);
}

char	*ft_hextoa(unsigned int hex, int upp)
{
	char	*value;
	int		len;

	len = hex_len(hex);
	value = ft_calloc(len + 1, sizeof(char));
	if (!value)
		return (0);
	fill_hex(value, hex, len, upp);
	return (value);
}
