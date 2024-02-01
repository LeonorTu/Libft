/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:25:59 by jtu               #+#    #+#             */
/*   Updated: 2024/01/19 18:52:46 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

# include <stdio.h> //

long	ft_atoi_long(const char *str)
{
	long	content;
	int		sign;

	content = 0;
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
		content = content * 10 + *str - '0';
		str++;
	}
	return (sign * content);
}

void	init_stack(t_stack **stack, char **argv)
{
	int	i;
	long	n;

	i = 0;
	(*stack)->a = NULL;
	(*stack)->b = NULL;
	while (argv[i])
	{
		if (invalid_argv(argv[i]))
			free_var(stack);
		n = ft_atoi_long(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			free_var(stack);
		if (duplicated_argv((*stack)->a, n))
			free_var(stack);
		add_node(&(*stack)->a, n);
		i++;
	}
	(*stack)->len_a = ft_lstsize((*stack)->a);
	(*stack)->len_b = 0;
}

t_list	*find_biggest(t_list *list)
{
	int		biggest;
	t_list	*biggest_node;

	biggest = INT_MIN;
	while (list)
	{
		if (list->content > biggest)
		{
			biggest = list->content;
			biggest_node = list;
		}
		list = list->next;
	}
	return (biggest_node);
}

t_list	*find_smallest(t_list *list)
{
	int		smallest;
	t_list	*smallest_node;

	smallest = INT_MAX;
	while (list)
	{
		if (list->content < smallest)
		{
			smallest = list->content;
			smallest_node = list;
		}
		list = list->next;
	}
	return (smallest_node);
}

t_list	*list_copy(const t_list *list)
{
	t_list	*copy;

	if (!list)
		return NULL;
	copy = malloc(sizeof(t_list));
	copy->content = list->content;
	copy->next = list_copy(list->next);
	return (copy);
}

t_list	*find_median(t_list *list)
{
	int		len;
	int		i;
	t_list	*sorted_list;

	sorted_list = list_copy(list);
	quick_sort(sorted_list, last_node(&sorted_list));
	len = ft_lstsize(sorted_list);
	i = 0;
	while (i < len / 2)
	{
		sorted_list = sorted_list->next;
		i++;
	}
	return (sorted_list);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (argc < 2 || (argc == 2 && !argv[1][0]))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_stack(stack, argv);
	}
	else
		init_stack(stack, argv + 1);
	if (!list_sorted(stack->a))
	{
		if (stack->len_a == 2)
			sa(stack->a);
		else if (stack->len_a == 3)
			sort_three(stack->a);
		else
			push_swap(stack);
	}

	while (stack->a != NULL) //
	{
		printf("the content of the a node: %d\n", stack->a->content);
		stack->a = stack->a->next;
	}

	while (stack->b != NULL) //
	{
		printf("the content of the b node: %d\n", stack->b->content);
		stack->b = stack->b->next;
	}

	// free_list(&a);
	// free_list(&b);
	return (0);
}
