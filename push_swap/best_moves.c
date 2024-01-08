/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:09:38 by jtu               #+#    #+#             */
/*   Updated: 2024/01/08 16:30:05 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next_number(int n, t_stack *a)
{
	int	next_n;
	int	len;
	t_stack	*a_temp;

	a_temp = a;
	len = stack_len(a);
	next_n = INT_MAX;
	while (len--)
	{
		if (n < a_temp->value && next_n > a_temp->value)
		{
			next_n = a_temp->value;
		}
		a_temp = a_temp->next;
	}
	if ()
	{
		next_n = a->value;

	}
	return (next_n);
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
		rotate_a(a);
		replace_rr(best_moves);
		if (count_bm(best_moves) < best_moves->total)
			copy_best_moves(best_moves);
		b_temp = b_temp->next;
		i++;
	}

}
