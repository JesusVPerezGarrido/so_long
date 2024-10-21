/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:44:20 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/14 11:30:30 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbr(int nbr)
{
	char	*str;
	int		length;

	str = ft_itoa(nbr);
	if (!str)
		return (-1);
	length = ft_printstr(str);
	free(str);
	return (length);
}

int	ft_printunbr(unsigned int nbr)
{
	char	*str;
	int		length;

	str = ft_uitoa(nbr);
	if (!str)
		return (-1);
	length = ft_printstr(str);
	free(str);
	return (length);
}
