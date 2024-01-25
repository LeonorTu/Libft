/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:25:59 by jtu               #+#    #+#             */
/*   Updated: 2024/01/25 19:20:20 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

# include <stdio.h> //

long	ft_atoi_long(const char *str)
{
	long	value;
	int		sign;

	value = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str ++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		value = value * 10 + *str - '0';
		str++;
	}
	return (sign * value);
}

void	init_stack(t_stack **stack, char **argv, int argc)
{
	int	i;
	long	n;

	i = 0;
	while (argv[i])
	{
		if (invalid_argv(argv[i]))
			free_var(stack);
		n = ft_atoi_long(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			free_var(stack);
		if (duplicated_argv(*stack, n))
			free_var(stack);
		add_node(stack, n);
		i++;
	}
	if (argc == 2)
		free_array(argv);
}

void	free_array(char **argv)
{
	int	i;

	if (!argv || !*argv)
		return ;
	i = -1;
	while (argv[i])
		free(argv[i++]);
	free(argv-1);
}

t_stack	*find_biggest(t_stack *stack)
{
	int		biggest;
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

t_stack	*find_smallest(t_stack *stack)
{
	int		smallest;
	t_stack	*smallest_node;

	smallest = INT_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack	*stack_copy(const t_stack *stack)
{
	t_stack	*copy;

	if (!stack)
		return (NULL);
	copy = malloc(sizeof(t_stack)); // leaks here
	if (!copy)
		return (NULL);
	copy->value = stack->value;
	copy->next = stack_copy(stack->next);
	return (copy);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_stack(&a, argv, argc);
	}
	else
		init_stack(&a, argv + 1, argc);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else if (stack_len(a) == 4)
			sort_four(&a, &b);
		else if (stack_len(a) == 5)
			sort_five(&a, &b);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
