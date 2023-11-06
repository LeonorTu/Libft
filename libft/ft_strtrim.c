/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:43:44 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 20:37:33 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1_trim;
	int		start;
	int		end;
	int		len;
	int		i;

	len = ft_strlen(s1);
	start = 0;
	end = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end < len - start && ft_strchr(set, s1[len - end - 1]))
		end++;
	s1_trim = malloc((len - start - end + 1) * sizeof(char));
	if (!s1_trim)
		return (NULL);
	i = 0;
	while (i < len - start - end)
	{
		s1_trim[i] = s1[i + start];
		i++;
	}
	s1_trim[i] = '\0';
	return (s1_trim);
}

// #include <stdio.h>
// int main(void)
// {
//     char *s1 = "   \t  \n\n \t\t  \n\n\n\t\n  ";;
//     char *set = " \t\n";

//     printf("s1: %s, set: %s\n", s1, set);
//     printf("After ft_strtrim: %s", ft_strtrim(s1, set));
// }
