/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:57:22 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 20:39:24 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

// #include <stdio.h>
// int main(void)
// {
//     int value1 = 42;
//     int value2 = 24;
//     t_list *node = ft_lstnew(&value1)
//     t_list *new_node = ft_lstnew(&value2);
//     node->next = new_node;

//     printf("lenth of lst: %d", ft_lstsize(node));
// }
