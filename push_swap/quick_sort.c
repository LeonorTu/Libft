/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:09:11 by jtu               #+#    #+#             */
/*   Updated: 2024/01/05 18:58:16 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**partition(t_stack *first, t_stack *last)
{
	int	temp;
	t_stack	*pivot;
	t_stack	*current;

	temp = 0;
	pivot = first;
	current = first;
	while (current && current != last)
	{
		if (current->value < last->value)
		{
			pivot = first;
			temp = first->value;
			first->value = current->value;
			current->value = temp;
			first = first->next;
		}
		current = current->next;
	}
	temp = first->value;
	first->value = last->value;
	last->value = temp;
	last = first->next;
	return (pivot);
}
