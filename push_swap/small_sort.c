/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:26:07 by jtu               #+#    #+#             */
/*   Updated: 2024/01/31 15:25:50 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = find_biggest(*a);
	if (*a == biggest_node)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*smallest_node;

	if (stack_sorted(*a))
		return ;
	smallest_node = find_smallest(*a);
	if (last_node(a) == smallest_node)
		rra(a, false);
	while (*a != smallest_node)
		ra(a, false);
	if (stack_sorted(*a))
		return ;
	pb(a, b, false);
	sort_three(a);
	pa(a, b, false);
}

// #include <stdio.h>  //
// void printList(t_stack *head) {
//     while (head != NULL) {
//         printf("%d ", head->value);
//         head = head->next;
//     }
//     printf("\n");
// }

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*smallest_node;
	t_stack	*temp;

	if (stack_sorted(*a))
		return ;
	temp = *a;
	smallest_node = find_smallest(temp);
	if (last_node(&temp) == smallest_node)
		rra(a, false);
	else if (temp->next == smallest_node)
		ra(a, false);
	else
	{
		temp = temp->next;
		if (temp->next == smallest_node)
		{
			ra(a, false);
			ra(a, false);
		}
		else if (temp->next->next == smallest_node)
		{
			rra(a, false);
			rra(a, false);
		}
	}
	pb(a, b, false);
	sort_four(a, b);
	pa(a, b, false);
	// printList(*a); //
}
