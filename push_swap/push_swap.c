/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:25:40 by jtu               #+#    #+#             */
/*   Updated: 2024/01/08 15:00:19 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //
void	push_median(t_stack	**a, t_stack **b)
{
	t_stack	*median_node;
	t_stack	*temp;
	int		i;
	int		len;

	temp = *a;
	median_node = find_median(temp);
	i = 0;
	while (temp->value != median_node->value)
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
		if (!max_value(*a))  //max_value ? 5 or 1
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

void	push_b2a(t_stack **a, t_stack **b)
{
	t_moves	*best_moves;

	best_moves = malloc(sizeof(t_moves));
	if (!best_moves)
		return (NULL);
	init_moves(best_moves);
	calculate_best_moves(a, b, best_moves);

}

void	push_swap(t_stack **a, t_stack **b)
{
	push_median(a, b);
	push_a2b(a, b);
	if (stack_len(a) == 3)
		sort_three(a);
	push_b2a(a, b);
}
