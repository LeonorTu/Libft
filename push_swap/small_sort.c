/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:26:07 by jtu               #+#    #+#             */
/*   Updated: 2024/01/08 13:00:51 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = find_biggest(*a);
	if (*a == biggest_node)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
	free(biggest_node);
}

void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*smallest_node;

	if (stack_sorted(*a))
		return ;
	smallest_node = find_smallest(*a);
	if (last_node(*a) == smallest_node)
		rra(a);
	while (*a != smallest_node)
		ra(a);
	if (stack_sorted(*a))
		return ;
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*smallest_node;
	t_stack	*temp;

	temp = *a;
	if (stack_sorted(temp))
		return ;
	smallest_node = find_smallest(temp);
	if (last_node(temp) == smallest_node)
		rra(a);
	else if (temp->next == smallest_node)
		ra(a);
	else
	{
		temp = temp->next;
		if (temp->next == smallest_node)
		{
			ra(a);
			ra(a);
		}
		else
		{
			rra(a);
			rra(a);
		}
	}
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}
