/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:56:50 by jtu               #+#    #+#             */
/*   Updated: 2023/12/30 20:03:12 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack{
	int	value;
	struct s_stack *next;
}	t_stack;

// Errors handling
void	free_stack(t_stack **stack);
void	free_var(t_stack **stack);
int		invalid_argv(char *str);
int		duplicated_argv(t_stack *stack, int n);

// Stack initiation
void	add_node(t_stack **stack, int n);
void	init_stack(t_stack **stack, char **argv);

// Stack util
bool	stack_sorted(t_stack *stack);
int		stack_len(t_stack *stack);
void	swap_node(t_stack **stack);
t_stack	*last_node(t_stack **stack);
void	rotate_stack(t_stack **stack);
void	reverse_rotate_stack(t_stack **stack);
void	push(t_stack **dst, t_stack **src);

// Commands
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	sa(t_stack **b);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// Algorithms

#endif
