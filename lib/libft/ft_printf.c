/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:21:22 by jeperez-          #+#    #+#             */
/*   Updated: 2024/10/14 11:30:30 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_argument(char c, va_list arg_list)
{
	if (c == 'c')
		return (ft_printchr(va_arg(arg_list, int)));
	if (c == 's')
		return (ft_printstr(va_arg(arg_list, char *)));
	if (c == 'p')
		return (ft_printptr(va_arg(arg_list, void *)));
	if (c == 'd' || c == 'i')
		return (ft_printnbr(va_arg(arg_list, int)));
	if (c == 'u')
		return (ft_printunbr(va_arg(arg_list, unsigned int)));
	if (c == 'x')
		return (ft_printhex(va_arg(arg_list, int), 0));
	if (c == 'X')
		return (ft_printhex(va_arg(arg_list, int), 1));
	if (c == '%')
		return (ft_printchr('%'));
	return (-1);
}

static int	print_format(const char *str, va_list arg_list)
{
	int	index;
	int	length;

	length = 0;
	index = -1;
	while (str[++index])
	{
		if (str[index] == '%')
			length += print_argument(str[++index], arg_list);
		else
			length += ft_printchr(str[index]);
	}
	return (length);
}

int	ft_printf(char const *str, ...)
{
	int		value;
	va_list	arg_list;

	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(arg_list, str);
	value = print_format(str, arg_list);
	return (value);
}
