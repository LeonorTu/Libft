/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:53:18 by jtu               #+#    #+#             */
/*   Updated: 2024/01/19 14:16:28 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_list(t_list *list)
{
	t_list	*temp;

	if (!list || !list->next)
		return ;
	temp = list;
	list = ft_lstlast(list);
	list->next = temp;
	list = temp->next;
	temp->next = NULL;
}

void	ra(t_stack *stack)
{
	rotate_list(stack->a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	rotate_list(stack->b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack)
{
	rotate_list(stack->a);
	rotate_list(stack->b);
	write(1, "rr\n", 3);
}
