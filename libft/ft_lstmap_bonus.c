/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:55:38 by jtu               #+#    #+#             */
/*   Updated: 2023/11/06 13:16:03 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Iterates the list ’lst’ and applies the function
 * ’f’ on the content of each node. Creates a new
 * list resulting of the successive applications of
 * the function ’f’. The ’del’ function is used to
 * delete the content of a node if needed.
 * @param lst - The address of a pointer to a node.
 * @param f - The address of the function used to
 * iterate on the list.
 * @param del - The address of the function used to
 * delete the content of a node if needed.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_lst;
	t_list *node;

	new_lst = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	// save_lst = new_lst;
	// while (lst && lst->next)
	// {
	// 	ft_lstadd_back(&new_lst, f(lst->content))
	// 	lst = lst->next;
	// 	new_lst->next = ft_lstnew(f(lst->content));
	// 	new_lst = new_lst->next;
	// 	if (!new_lst)
	// 	{
	// 		ft_lstclear(&new_lst, del);
	// 		return (NULL);
	// 	}
	// }
	// new_lst->next = NULL;
	return (new_lst);
}

#include <stdio.h>
void	*node_add(void *content)
{
	*(int*)content = *(int*)content + 2;
	printf("the value of the node: %d\n", *(int*)content);
	return (content);
}

void	del_node(void *content)
{
    free(content);
}

int	main(void)
{
    t_list *node1 = malloc(sizeof(t_list));
    node1->content = malloc(sizeof(int));
    *(int *)(node1->content) = 42;
    t_list *node2 = malloc(sizeof(t_list));
    node2->content = malloc(sizeof(int));
    *(int *)(node2->content) = 24;
	t_list *node3 = malloc(sizeof(t_list));
    node3->content = malloc(sizeof(int));
    *(int *)(node3->content) = 12;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    printf("the value of the first node in list: %d\n", *(int *)((*node1).content));
    printf("the value of the second node in list: %d\n", *(int *)((*node2).content));
	printf("the value of the third node in list: %d\n", *(int *)((*node3).content));

    t_list *new_lst = ft_lstmap(node1, node_add, del_node);
	// printf("%d\n", *(int *)((ft_lstlast(new_lst))->content));
    printf("the value of the first node in new list: %d\n", *(int *)((*new_lst).content));
	new_lst = new_lst->next;
    printf("the value of the second node in new list: %d\n", *(int *)((*new_lst).content));
	new_lst = new_lst->next;
	printf("the value of the third node in new list: %d\n", *(int *)((*new_lst).content));
}
