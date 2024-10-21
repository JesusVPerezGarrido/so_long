/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:37:48 by jeperez-          #+#    #+#             */
/*   Updated: 2024/09/18 15:50:24 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_overflow(size_t a, size_t b)
{
	size_t	test;

	if (a == 0 || b == 0)
		return (0);
	test = a * b;
	if (test / a != b)
		return (1);
	else
		return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*value;
	size_t	mem_size;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (is_overflow(nmemb, size))
		return (0);
	mem_size = nmemb * size;
	value = malloc(mem_size);
	if (!value)
		return (0);
	ft_bzero(value, mem_size);
	return (value);
}
