/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:25:40 by jtu               #+#    #+#             */
/*   Updated: 2024/01/19 20:40:32 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //

void	push_median(t_list **a, t_list **b)
{
	t_list	*median_node;
	t_list	*temp;
	int		i;
	int		len;

	temp = *a;
	median_node = find_median(temp);
	i = 0;
	while (temp->content != median_node->content)
	{
		temp = temp->next;
		i++;
	}
	len = stack_len(*a);
	if (i <= len - i)
	{
		while (i--)
			ra(a);
	}
	else
	{
		i = len - i;
		while (i--)
			rra(a);
	}
	pb(a, b);
}

void	push_a2b(t_stack **a, t_stack **b)
{
	int	i;

	i = stack_len(*a);
	while (i--)
	{
		if (!max_content(*a))  //max_content ? 5 or 1
		{
			pb(a, b);
			if (*b > median)  //median
				rb(b);
		}
		else
			ra(a);
	}
}

void	init_moves(t_moves *moves)
{
	moves->nra = 0;
	moves->nrb = 0;
	moves->nrr = 0;
	moves->nrra = 0;
	moves->nrrb = 0;
	moves->nrrr = 0;
	moves->total = INT_MAX;
}

void	apply_best_moves(t_stack *a, t_stack *b, t_moves *best_moves)
{
	while (best_moves->nra--)
		ra(a);
	while (best_moves->nrb--)
		rb(a);
	while (best_moves->nrr--)
		rr(a, b);
	while (best_moves->nrra--)
		rra(a);
	while (best_moves->nrrb--)
		rrb(a);
	while (best_moves->nrrr--)
		rrr(a, b);
	pa(a, b);
}

// void	push_b2a(t_stack **a, t_stack **b)
// {
// 	t_moves	*best_moves;
// 	int	len;

// 	best_moves = malloc(sizeof(t_moves));
// 	if (!best_moves)
// 		return (NULL);
// 	init_moves(best_moves);
// 	len = stack_len(*b);
// 	when (len--)
// 	{
// 		calculate_best_moves(a, b, best_moves);
// 		apply_best_moves(a, b, best_moves);
// 		best_moves->total = INT_MAX;
// 	}
// 	while ()

// }

void	push_swap(t_stack *stack)
{
	push_median(&stack->a, &stack->b);
	push_a2b(&stack->a, &stack->b);
	if (stack->len_a == 3)
		sort_three(stack->a);
	// push_b2a(&stack->a, &stack->b);
}
