/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:36:01 by jeperez-          #+#    #+#             */
/*   Updated: 2024/09/19 17:04:40 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*value;
	t_list	*placeholder;

	value = 0;
	while (lst)
	{
		placeholder = ft_lstnew((*f)(lst->content));
		if (!placeholder)
		{
			ft_lstclear(&value, (*del));
			return (0);
		}
		ft_lstadd_back(&value, placeholder);
		lst = lst->next;
	}
	return (value);
}
