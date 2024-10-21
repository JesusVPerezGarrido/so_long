/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:24:55 by jeperez-          #+#    #+#             */
/*   Updated: 2024/09/19 16:28:51 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*previous;

	if (*lst == 0)
		return ;
	while ((*lst)->next)
	{
		previous = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(previous, (*del));
	}
	ft_lstdelone(*lst, (*del));
	*lst = 0;
}
