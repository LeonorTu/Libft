/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:27:27 by jtu               #+#    #+#             */
/*   Updated: 2023/11/04 16:05:49 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Deletes and frees the given node and every
 * successor of that node, using the function ’del’
 * and free(3).
 * Finally, the pointer to the list must be set to
 * NULL.
 * @param lst - The address of a pointer to a node.
 * @param del - The address of the function used to
 *              delete the content of the node.
 * @return None
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !(*lst))
		return ;
	ft_lstclear(&((*lst)->next), del);
	ft_lstdelone(*lst, del);
	*lst = NULL;
}

// void	del_node(void *content)
// {
// 	free(content);
// }

// #include <stdio.h>

// int	main(void)
// {
// 	t_list *node;
// 	node = malloc(sizeof(t_list));
// 	node->content = malloc(sizeof(int));
// 	*(int *)(node->content) = 42;
// 	t_list *new_node1;
// 	new_node1 = malloc(sizeof(t_list));
// 	new_node1->content = malloc(sizeof(int));
// 	*(int *)(new_node1->content) = 24;
// 	node->next = new_node1;
// 	t_list *new_node2;
// 	new_node2 = malloc(sizeof(t_list));
// 	new_node2->content = malloc(sizeof(int));
// 	*(int *)(new_node2->content) = 55;
// 	new_node2->next = NULL;
// 	new_node1->next = new_node2;

// 	printf("the value of the first node in list: %d\n", *(int *)((*node).content));
// 	printf("the value of the second node in list: %d\n", *(int *)((*(node->next)).content));
// 	printf("the value of the third node in list: %d\n", *(int *)((*(new_node1->next)).content));

// 	ft_lstclear(&node, del_node);
// 	if (!node)
// 		printf("SUCCESS!\n");
// }
