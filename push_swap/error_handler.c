/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:05:40 by jtu               #+#    #+#             */
/*   Updated: 2023/12/30 21:50:49 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	if (!stack || !(*stack))
		return ;
	free_stack(&((*stack)->next));
	free(*stack);
	*stack = NULL;
}

void	free_var(t_stack **stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}

// void	free_arr()
// {
// 	free
// }

int	invalid_argv(char *str)
{
	if (*str == '+' || *str == '-')
	{
		str++;
		if (!*str)
			return (1);
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

int	duplicated_argv(t_stack *stack, int n)
{
	while (stack)
	{
		if (stack->value == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}
