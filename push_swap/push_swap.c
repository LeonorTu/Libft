/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:25:59 by jtu               #+#    #+#             */
/*   Updated: 2023/12/22 20:13:57 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// # include "./libft/libft.h" //
// # include <stdbool.h> //
// # include <stdlib.h> //
// # include <limits.h> //
// # include <stdio.h> //

typedef struct s_stack{
	int	value;
	struct s_stack *prev;
	struct s_stack *next;
}	t_stack;

bool	stack_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

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
	write(1, "ERROR\n", 6);
	exit(1);
}

// void	free_arr()
// {
// 	free
// }

int	invalid_argv(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
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

void	add_node(t_stack **stack, int n)
{
	t_stack	*new_node;
	t_stack	*temp;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = n;
	new_node->next = NULL;
	temp = *stack;
	if (!(*stack))
	{
		*stack = new_node;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}

void init_stack(t_stack **stack, char **argv)
{
	int	i;
	int	n;
	t_stack	*new_node;

	i = 0;
	while (argv[i])
	{
		if (invalid_argv(argv[i]))
			free_var(stack);
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_var(stack);
		if (duplicated_argv(*stack, n))
			free_var(stack);
		add_node(stack, n);
		i++;
	}
}

int	stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	swap_node(t_stack **stack)
{
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_stack(&a, argv);
	}
	else
		init_stack(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(a);

	}

	// while (a != NULL) //
	// {
	// 	printf("the value of the node: %d\n", a->value);
	// 	a = a->next;
	// }

	free_stack(&a);
	return (0);
}
