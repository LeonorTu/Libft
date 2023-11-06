/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:53:41 by jtu               #+#    #+#             */
/*   Updated: 2023/11/04 16:04:48 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Takes as a parameter a node and frees the memory of
 * the node’s content using the function ’del’ given
 * as a parameter and free the node. The memory of
 * ’next’ must not be freed.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}

// void del_node(void *content)
// {
//     free(content);
// }

// #include <stdio.h>
// int main(void)
// {
//     t_list *node;
//     node = malloc(sizeof(t_list));
//     node->content = malloc(sizeof(int));
//     *(int *)(node->content) = 42;
//     t_list *new_node;
//     new_node = malloc(sizeof(t_list));
//     new_node->content = malloc(sizeof(int));
//     *(int *)(new_node->content) = 24;
//     node->next = new_node;

//     printf("the value of the first node in list: %d\n", *(int *)((*node).content));
//     printf("the value of the second node in list: %d\n", *(int *)((*(node->next)).content));

//     ft_lstdelone(node, del_node);
//     printf("the value of the last node in list: %d\n", *(int *)((*(new_node)).content));
// }
