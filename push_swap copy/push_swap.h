/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:56:50 by jtu               #+#    #+#             */
/*   Updated: 2024/01/19 18:59:44 by jtu              ###   ########.fr       */
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
	t_list	*a;
	t_list	*b;
	int		len_a;
	int		len_b;
}	t_stack;

typedef struct s_values
{
	int	min;
	int	max;
}	t_values;

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
int		duplicated_argv(t_list *list, int n);

// Stack initiation
void	add_node(t_list **list, int n);
void	init_stack(t_stack **stack, char **argv);

// Stack util
bool	stack_sorted(t_stack *stack);
int		stack_len(t_stack *stack);
t_stack	*last_node(t_stack **stack);
void	swap_node(t_stack **stack);
void	rotate_stack(t_stack **stack);
void	reverse_rotate_stack(t_stack **stack);
void	push(t_stack **dst, t_stack **src);
t_list	*find_biggest(t_list *list);
t_list	*find_smallest(t_list *list);

// Commands
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

// Algorithms
t_list	*find_median(t_list *list);
void	push_median(t_list **a, t_list **b);
void	sort_three(t_list *a);
void	sort_four(t_stack **a, t_stack **b);
void	quick_sort(t_stack *head, t_stack *tail);
void	push_swap(t_stack *stack);

#endif
