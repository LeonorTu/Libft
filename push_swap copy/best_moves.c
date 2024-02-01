/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:09:38 by jtu               #+#    #+#             */
/*   Updated: 2024/01/19 20:39:13 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_number(int n, t_stack *a)
{
	int	next_n;
	int next_n_0;
	int	len;
	int	found;
	t_stack	*a_temp;

	a_temp = a;
	len = stack_len(a);
	next_n = INT_MAX;
	next_n_0 = INT_MAX;
	found = 0;
	while (len--)
	{
		if (n < a_temp->value && next_n > a_temp->value)
		{
			next_n = a_temp->value;
			found = 1;
		}
		if (next_n > a_temp->value)
			next_n_0 = a_temp->value;
		a_temp = a_temp->next;
	}
	if (found == 1)
		return (next_n);
	return (next_n_0);
}

void	rotate_a(t_stack *a, int n, t_moves *best_moves)
{
	int	i;
	int	len;
	t_stack	*temp;

	i = 0;
	len = stack_len(a);
	temp = a;
	while (i < len && a->value != n)
	{
		temp = temp->next;
		i++;
	}
	if (i <= len - i)
		best_moves->nra = i;
	else
		best_moves->nrra = len - i;
}

void	replace_rr(t_moves *best_moves)
{
	while (best_moves->nra && best_moves->nrb)
	{
		best_moves->nra--;
		best_moves->nrb--;
		best_moves->nrr++;
	}
	while (best_moves->nrra && best_moves->nrrb)
	{
		best_moves->nrra--;
		best_moves->nrrb--;
		best_moves->nrrr++;
	}
}

int	count_bm(t_moves *best_moves)
{
	int	total;

	total = best_moves->nra + best_moves->nrb + best_moves->nrr
	+ best_moves->nrra + best_moves->nrrb + best_moves->nrrr;
	best_moves->total = total;
	return (total);
}

void	calculate_best_moves(t_stack *a, t_stack *b, t_moves *best_moves)
{
	int	len;
	int	i;
	int	next_n;
	t_stack	*b_temp;

	len = stack_len(b);
	i = 0;
	while (i < len)
	{
		if (i <= len - i)
			best_moves->nrb = i;
		else
			best_moves->nrrb = len - i;
		next_n = next_number(b_temp->value, a);
		rotate_a(a, next_n, best_moves);
		replace_rr(best_moves);
		if (count_bm(best_moves) < best_moves->total)
			copy_best_moves(best_moves);
		b_temp = b_temp->next;
		i++;
	}
}