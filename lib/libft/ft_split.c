/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:22:44 by jeperez-          #+#    #+#             */
/*   Updated: 2024/09/18 15:35:05 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	split_count(char const *s, char c)
{
	int	value;
	int	apart;
	int	index;

	apart = 1;
	value = 0;
	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			apart = 1;
		else
		{
			if (apart)
				value++;
			apart = 0;
		}
		index++;
	}
	return (value);
}

static int	malloc_error(char **matrix, int size)
{
	while (--size >= 0)
		free(matrix[size]);
	free(matrix);
	return (0);
}

static char	*split_substr(const char *str, char delim, int iteri)
{
	int	value;
	int	index;
	int	start;

	index = 0;
	value = 0;
	while (value < iteri)
	{
		while (str[index] && str[index] == delim)
			index++;
		start = index;
		while (str[index] && str[index] != delim)
			index++;
		value++;
	}
	return (ft_substr(str, start, index - start));
}

static void	fill_split(char const *s, char delim, char **matrix, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		matrix[index] = split_substr(s, delim, index + 1);
		if (!matrix[index])
		{
			malloc_error(matrix, index - 1);
			return ;
		}
		index++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**value;
	int		size;

	size = split_count(s, c);
	value = ft_calloc(sizeof(char *), size + 1);
	if (!value)
		return (0);
	fill_split(s, c, value, size);
	return (value);
}
