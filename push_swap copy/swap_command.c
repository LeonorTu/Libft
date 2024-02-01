/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:55:46 by jtu               #+#    #+#             */
/*   Updated: 2024/01/19 14:46:54 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_node(t_list *list)
{
	t_list	*temp;

	if (!list || !list->next)
		return ;
	temp = list;
	list = list->next;
	temp->next = list->next;
	list->next = temp;
}

void	sa(t_stack *stack)
{
	swap_node(stack->a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	swap_node(stack->b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack)
{
	swap_node(stack->a);
	swap_node(stack->b);
	write(1, "ss\n", 3);
}
