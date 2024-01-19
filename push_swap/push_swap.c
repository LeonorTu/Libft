/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:25:40 by jtu               #+#    #+#             */
/*   Updated: 2024/01/19 20:57:44 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //
void	push_median(t_stack	**a, t_stack **b, t_values *values)
{
	t_stack	*temp;
	int		i;
	int		len;

	temp = *a;
	i = 0;
	while (temp->value != values->median)
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

int	max_value(int n, t_values *values)
{
	return(n == values->max1 || n == values->max2 ||n == values->max3
	||n == values->max4 || n == values->max5);
}

void	push_a2b(t_stack **a, t_stack **b, t_values *values)
{
	int	i;

	i = stack_len(*a);
	while (i--)
	{
		if (!max_value((*a)->value, values))
		{
			pb(a, b);
			if ((*b)->value > values->median)
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
		ra(&a);
	while (best_moves->nrb--)
		rb(&a);
	while (best_moves->nrr--)
		rr(&a, &b);
	while (best_moves->nrra--)
		rra(&a);
	while (best_moves->nrrb--)
		rrb(&a);
	while (best_moves->nrrr--)
		rrr(&a, &b);
	pa(&a, &b);
}

void	push_b2a(t_stack **a, t_stack **b, t_values *values)
{
	t_moves	*best_moves;
	t_stack	*temp;
	int	len_a;
	int	len_b;
	int	i;

	best_moves = malloc(sizeof(t_moves));
	if (!best_moves)
		return ;
	init_moves(best_moves);
	len_a = stack_len(*a);
	len_b = stack_len(*b);
	while (len_b--)
	{
		calculate_best_moves(*a, *b, best_moves);
		apply_best_moves(*a, *b, best_moves);
		best_moves->total = INT_MAX;
	}
	temp = *a;
	i = 0;
	while (temp->value != values->min)
	{
		temp = temp->next;
		i++;
	}
	if (i <= len_a - i)
		while (i--)
			ra(a);
	else
	{
		i = len_a - i;
		while (i--)
			rra(a);
	}
	free(best_moves);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_values	*values;

	values = find_values(*a, values);
	push_median(a, b, values);
	push_a2b(a, b, values);
	if (stack_len(*a) == 3)
		sort_three(a);
	else if (stack_len(*a) == 4)
		sort_four(a, b);
	else
		sort_five(a, b);
	push_b2a(a, b, values);
}
