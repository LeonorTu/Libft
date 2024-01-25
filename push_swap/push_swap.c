/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:25:40 by jtu               #+#    #+#             */
/*   Updated: 2024/01/25 19:22:36 by jtu              ###   ########.fr       */
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
	return (n == values->max1 || n == values->max2 ||n == values->max3
	||n == values->max4 || n == values->max5);
}

void	push_a2b(t_stack **a, t_stack **b, t_values *values)
{
	int	len;

	len = stack_len(*a);
	if (len == 5)
		return ;
	while (len--)
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

void	apply_best_moves(t_stack **a, t_stack **b, t_moves *best_moves)
{
	while (best_moves->nrr--)
		rr(a, b);
	while (best_moves->nrrr--)
		rrr(a, b);
	while (best_moves->nrrb--)
		rrb(b);
	while (best_moves->nrb--)
		rb(b);
	while (best_moves->nra--)
		ra(a);
	while (best_moves->nrra--)
		rra(a);
	pa(a, b);
}

void	push_b2a(t_stack **a, t_stack **b, t_values *values)
{
	t_moves	*best_moves;
	t_stack	*temp;
	int	len_a;
	int	len_b;
	int	i;

	best_moves = malloc(sizeof(t_moves)); // no leaks here
	if (!best_moves)
		free_everything(a, b, values, best_moves);
	init_moves(best_moves);
	len_b = stack_len(*b);
	while (len_b--)
	{
		calculate_best_moves(a, b, values, best_moves);
		apply_best_moves(a, b, best_moves);
		best_moves->total = INT_MAX;
	}
	temp = *a;
	i = 0;
	while (temp->value != values->min)
	{
		temp = temp->next;
		i++;
	}
	len_a = stack_len(*a);
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

t_values	*find_values(t_stack *stack, t_values *values)
{
	int		len;
	int		i;
	t_stack	*sorted_stack;

	sorted_stack = stack_copy(stack);
	quick_sort(sorted_stack, last_node(&sorted_stack));
	len = stack_len(sorted_stack);
	values->min = sorted_stack->value;
	i = -1;
	while (++i < len - 1)
	{
		if (i == len / 2 + len % 2 - 1)
			values->median = sorted_stack->value;
		if (i == len - 2)
			values->max2 = sorted_stack->value;
		if (i == len - 3)
			values->max3 = sorted_stack->value;
		if (i == len - 4)
			values->max4 = sorted_stack->value;
		if (i == len - 5)
			values->max5 = sorted_stack->value;
		sorted_stack = sorted_stack->next;
	}
	values->max1 = sorted_stack->value;
	free_stack(&sorted_stack);
	return (values);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_values	*values;

	values = malloc(sizeof(t_values));   // no leaks here
	if (!values)
	{
		free_stack(a);
		free_stack(b);
	}
	values = find_values(*a, values);
	push_median(a, b, values);
	push_a2b(a, b, values);
	if (stack_len(*a) == 4)
		sort_four(a, b);
	else
		sort_five(a, b);
	push_b2a(a, b, values);
	free(values);
}
