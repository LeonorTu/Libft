/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:54:36 by jtu               #+#    #+#             */
/*   Updated: 2024/01/19 14:22:26 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack(t_list *list)
{
	t_list	*temp;
	t_list	*last;

	if (!list || !list->next || !list->next->next)
		return ;
	temp = list;
	while (list->next->next)
		list = list->next;
	last = list->next;
	list->next = NULL;
	last->next = temp;
	list = last;
}

void	rra(t_stack *stack)
{
	reverse_rotate_stack(stack->a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	reverse_rotate_stack(stack->b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack)
{
	reverse_rotate_stack(stack->a);
	reverse_rotate_stack(stack->b);
	write(1, "rrr\n", 4);
}
