/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:09:07 by jtu               #+#    #+#             */
/*   Updated: 2024/01/19 13:48:58 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	list_sorted(t_list *list)
{
	if (list == NULL)
		return (1);
	while (list->next)
	{
		if (list->content > list->next->content)
			return (false);
		list = list->next;
	}
	return (true);
}

void	add_node(t_list **list, int n)
{
	t_list	*new_node;
	t_list	*temp;

	if (!list)
		return ;
	new_node = ft_lstnew(n);
	ft_lstadd_back(list, new_node);
}

