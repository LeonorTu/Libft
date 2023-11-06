/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:47:30 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 21:06:39 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
// #include <stdio.h>
// int main(void)
// {
//     int value1 = 42;
//     int value2 = 24;
//     t_list *node = ft_lstnew(&value1);
//     t_list **lst = &node;
//     t_list *new_node = ft_lstnew(&value2);
//     printf("the value of the first node in list: %d\n", *(int *)((*lst)->content));

//     ft_lstadd_front(lst, new_node);
//     printf("the value of the first node in list: %d\n", *(int *)((*lst)->content));
// }
