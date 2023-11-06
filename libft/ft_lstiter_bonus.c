/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:54:56 by jtu               #+#    #+#             */
/*   Updated: 2023/11/04 15:34:54 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Iterates the list ’lst’ and applies the function
 * ’f’ on the content of each node.
 * @param lst - The address of a pointer to a node.
 * @param f -  The address of the function used to iterate
 * on the list.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// #include <stdio.h>
// void print_node(void *content)
// {
// 	printf("the value of the node: %s\n", (char*)content);
// }

// int main(void)
// {
// 	t_list *node1 = ft_lstnew("Hello");
// 	t_list *node2 = ft_lstnew("world");
// 	t_list *node3 = ft_lstnew("!");
// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = NULL;
// 	printf("the value of the first node in list: %s\n", (char *)((*node1).content));
// 	printf("the value of the second node in list: %s\n", (char *)((*node2).content));
// 	printf("the value of the third node in list: %s\n", (char *)((*node3).content));

// 	ft_lstiter(node1, print_node);
// }
