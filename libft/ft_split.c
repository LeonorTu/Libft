/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:42:12 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 20:37:46 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates (with malloc(3)) and returns an array
 * of strings obtained by splitting ’s’ using the
 * character ’c’ as a delimiter. The array must end
 * with a NULL pointer.
*/

int	count_words(char const *s, char c)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			word++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		word++;
	return (word);
}

char	*ft_strcpy(char *dest, char const *src, char c)
{
	int	i;

	i = 0;
	while (src[i] != c && src[i])
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;
	int		k;

	ptr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			while (s[i + j] != c && s[i + j])
				j++;
			ptr[k] = malloc(sizeof(char) * (j + 1));
			ft_strcpy(ptr[k], s + i, c);
			i += j;
			k++;
		}
	}
	ptr[k] = 0;
	return (ptr);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *str = "      split       this for   me  !       ";
//     char c = ' ';
// 	char **result = ft_split(str, c);
// 	int	i = 0;

// 	printf("%s\n", str);
// 	while(result[i])
// 	{
// 		printf("%s\n", result[i]);
// 		free(result[i]); // Free individual strings.
//         i++;
// 	}
// }
