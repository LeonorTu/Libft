/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:05:40 by jtu               #+#    #+#             */
/*   Updated: 2024/01/19 18:56:39 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_node(void *content)
{
	free(content);
}

void	free_var(t_stack **stack)
{
	ft_lstclear(&(*stack)->a, del_node);
	ft_lstclear(&(*stack)->b, del_node);
	free(stack);
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

int	duplicated_argv(t_list *list, int n)
{
	while (list)
	{
		if (list->content == n)
			return (1);
		list = list->next;
	}
	return (0);
}
