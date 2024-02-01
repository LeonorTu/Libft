/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:57:02 by jtu               #+#    #+#             */
/*   Updated: 2024/01/19 14:10:43 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list *dst, t_list *src)
{
	t_list	*first_node;

	if (!src)
		return ;
	first_node = src;
	src = src->next;
	if (dst)
	{
		first_node->next = dst;
		dst = first_node;
	}
	else
	{
		dst = first_node;
		first_node->next = NULL;
	}
}

void	pa(t_stack *stack)
{
	push(stack->a, stack->b);
	stack->len_a--;
	stack->len_b++;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack)
{
	push(stack->b, stack->a);
	write(1, "pb\n", 3);
}
