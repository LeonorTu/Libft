/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:46:04 by jtu               #+#    #+#             */
/*   Updated: 2023/11/06 13:18:58 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	else
	{
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = new;
	}
}

// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	t_list *l = ((void *)0);
// 	t_list *n = ft_lstnew(strdup("OK"));

// 	ft_lstadd_back(&l, n);
// 	if (l == n && !strcmp(l->content, "OK"))
// 	{
// 		free(l->next);
// 		free(l);
// 		printf("success");
// 	}
// 	free(l->next);
// 	free(l);
// 	printf("fail");
// }
#include <stdio.h>
int main(void)
{
    int value1 = 42;
    int value2 = 24;
	int value3 = 12;
    t_list *node = ft_lstnew(&value1);
    t_list **lst = &node;
    t_list *new_node1 = ft_lstnew(&value2);
	t_list *new_node2 = ft_lstnew(&value3);
    printf("the value of the last node in list: \
	%d\n",*(int *)((*ft_lstlast(*lst)).content));

    ft_lstadd_back(lst, new_node1);
    printf("the value of the last node in list: \
	%d\n",*(int *)((*ft_lstlast(*lst)).content));

	ft_lstadd_back(lst, new_node2);
    printf("the value of the last node in list: \
	%d\n",*(int *)((*ft_lstlast(*lst)).content));
}
