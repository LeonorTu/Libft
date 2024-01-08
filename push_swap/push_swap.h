/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:56:50 by jtu               #+#    #+#             */
/*   Updated: 2024/01/08 14:59:31 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int	value;
	struct s_stack *next;
}	t_stack;

typedef struct s_moves
{
	int	nra;
	int	nrb;
	int	nrr;
	int	nrra;
	int	nrrb;
	int	nrrr;
	int	total;
}	t_moves;

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
t_stack	*last_node(t_stack **stack);
void	swap_node(t_stack **stack);
void	rotate_stack(t_stack **stack);
void	reverse_rotate_stack(t_stack **stack);
void	push(t_stack **dst, t_stack **src);
t_stack	*find_biggest(t_stack *stack);
t_stack	*find_smallest(t_stack *stack);

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
t_stack	*find_median(t_stack *stack);
void	push_median(t_stack	**a, t_stack **b);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	quick_sort(t_stack *head, t_stack *tail);
void	push_swap(t_stack **a, t_stack **b);

#endif
