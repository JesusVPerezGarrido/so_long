/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:11:44 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/14 11:30:30 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printptr(void *ptr)
{
	char	*str;
	int		length;

	if (!ptr)
		return (ft_printstr("(nil)"));
	str = ft_ptrtoa(ptr);
	if (!str)
		return (-1);
	length = ft_printstr(str);
	free (str);
	return (length);
}
