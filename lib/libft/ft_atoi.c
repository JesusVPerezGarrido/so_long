/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:23:28 by jeperez-          #+#    #+#             */
/*   Updated: 2024/09/18 13:28:19 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(char c)
{
	if (c >= '\t' && c <= '\r')
		return (1);
	if (c == 32)
		return (1);
	return (0);
}

static int	get_nbr(const char *nptr)
{
	int	index;
	int	nbr;

	nbr = 0;
	index = 0;
	while (ft_isdigit(nptr[index]))
	{
		nbr *= 10;
		nbr += nptr[index] - 48;
		index++;
	}
	return (nbr);
}

int	ft_atoi(const char *nptr)
{
	int	index;
	int	sign;

	index = 0;
	while (isspace(nptr[index]))
		index++;
	sign = 1;
	if (nptr[index] == '-')
	{
		sign = -1;
		index++;
	}
	else if (nptr[index] == '+')
		index++;
	return (get_nbr(nptr + index) * sign);
}
