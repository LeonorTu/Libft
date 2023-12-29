/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:25:59 by jtu               #+#    #+#             */
/*   Updated: 2023/12/29 17:50:09 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

# include <stdio.h> //

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

void	init_stack(t_stack **stack, char **argv)
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
	t_stack	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

t_stack	*last_node(t_stack **stack)
{
	while ((*stack)->next)
		*stack = (*stack)->next;
	return (*stack);
}

void	sa(t_stack **a)
{
	swap_node(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap_node(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap_node(a);
	swap_node(b);
	write(1, "ss\n", 3);
}

void rotate_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = last_node(stack);
	(*stack)->next = temp;
	*stack = temp->next;
	temp->next = NULL;
}

void	ra(t_stack **a)
{
	rotate_stack(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate_stack(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate_stack(a);
	rotate_stack(b);
	write(1, "rr\n", 3);
}

void	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	temp = *stack;
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	last = (*stack)->next;
	(*stack)->next = NULL;
	last->next = temp;
	*stack = last;
}

void	rra(t_stack **a)
{
	reverse_rotate_stack(a);
	write(1, "rra\n", 3);
}

void	rrb(t_stack **b)
{
	reverse_rotate_stack(b);
	write(1, "rrb\n", 3);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	write(1, "rrr\n", 3);
}

t_stack	*find_biggest(t_stack *stack)
{
	int	biggest;
	t_stack	*biggest_node;

	biggest = INT_MIN;
	while (stack)
	{
		if (stack->value > biggest)
		{
			biggest = stack->value;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

void	small_sort(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = find_biggest(*a);
	if (*a == biggest_node)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	push_swap(t_stack **a, t_satck **b)
{
	
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
			sa(&a);
		else if (stack_len(a) == 3)
			small_sort(&a);
		else
			push_swap(&a, &b);
	}

	while (a != NULL) //
	{
		printf("the value of the node: %d\n", a->value);
		a = a->next;
	}

	free_stack(&a);
	return (0);
}
