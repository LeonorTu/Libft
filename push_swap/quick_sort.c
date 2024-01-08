/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:09:11 by jtu               #+#    #+#             */
/*   Updated: 2024/01/07 19:00:55 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //

t_stack	*partition(t_stack *head, t_stack *tail)
{
	int	temp;
	t_stack	*pivot;
	t_stack	*current;

	temp = 0;
	pivot = head;
	current = head;
	while (current && current != tail)
	{
		if (current->value < tail->value)
		{
			pivot = head;
			temp = head->value;
			head->value = current->value;
			current->value = temp;
			head = head->next;
		}
		current = current->next;
	}
	temp = head->value;
	head->value = tail->value;
	tail->value = temp;
	return (pivot);
}

void	quick_sort(t_stack *head, t_stack *tail)
{
	t_stack	*pivot;

	if (head == tail)
		return ;
	pivot = partition(head, tail);
	if (pivot != NULL && pivot->next != NULL)
		quick_sort(pivot->next, tail);
	if (pivot != NULL && head != pivot)
		quick_sort(head, pivot);
}
