/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:07:20 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 20:50:59 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// #include <stdio.h>
// int main(void)
// {
//     int value1 = 42;
//     int value2 = 24;
//     t_list *node = ft_lstnew(&value1);
//     t_list *new_node = ft_lstnew(&value2);
//     node->next = new_node;

//     printf("last node: %d", *(int *)(ft_lstlast(node)->content));
// }
