#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wctype.h>

void	check_isalpha(void)
{
	printf("Is 'c' an alphabet?\nft_isalpha result:%d\n", ft_isalpha('c'));
	printf("isalpha result:%d\n", isalpha('a'));
}

void	check_isdigit(void)
{
	printf("Is 'a' a digit?\nft_isdigit result:%d\n", ft_isdigit('a'));
	printf("isdigit result:%d\n", isdigit('a'));
	printf("Is 'a' a digit?\nft_isdigit result:%d\n", ft_isdigit('1'));
	printf("isdigit result:%d\n", isdigit('1'));
}

void	check_isalnum(void)
{
	printf("Is 'c' an alphanumeric?\nft_isalnum result:%d\n", ft_isalnum('c'));
	printf("isalnum result:%d\n", isalnum('c'));
}

void	check_isascii(void)
{
	printf("Is 'ö' ascii?\nft_isascii result:%d\n", ft_isascii(L'ö'));
	printf("isascii result:%d\n", isascii(L'ö'));
}

void	check_isprint(void)
{
	printf("Is 'a' printable?\nft_isprint result:%d\n", ft_isprint('a'));
	printf("isprint result:%d\n", isprint('a'));
	printf("Is 'ö' printable?\nft_isprint result:%d\n", ft_isprint(L'ö'));
	printf("isprint result:%d\n", isprint(L'ö'));
}

void	check_strlen(void)
{
	char abcd[8] = "acdhsjbg";
	char str[12] = "Hello World!";
	char abc[4] = "acbg";
	int	i = 0;

	while (i < 10)
	{
		printf("The number of characters in \"%s\" is %ld.\n", str, ft_strlen(str));
		i++;
	}
}

void	check_memset(void)
{

    int arr[5];
    size_t n = sizeof(arr) / sizeof(arr[0]);

    // Initialize the entire array to 0
    ft_memset(arr, 3, n * sizeof(int));

    // Print the initialized array
    for (size_t i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    printf("\n");

    //int s = 48;
    //int i = 0;

    //while (i < 3)
    //{
       // printf("%c", ((char*)ft_memset(s, 2, 3))[i++]);
    //}
}

void	check_memcpy(void)
{
    char src[] = "test basic du memcpy !";
	char buff1[22];
    char buff2[22];

    printf("ft_memcpy result: %s\n",ft_memcpy(buff1, src, 22));
    printf("memcpy result: %s\n", memcpy(buff2, src, 22));
}

void	check_bzero(void)
{
    int arr[5];
    size_t i = 0;
    size_t n = sizeof(arr) / sizeof(arr[0]);

    // Initialize the entire array to 0
    ft_bzero(arr, n * sizeof(int));

    // Print the initialized array
    while(i < n)
        printf("%d\n", arr[i++]);
    printf("\n");
}


void	check_memmove(void)
{
    // char src1[] = "Bye";
    // //ft_memmove(src1 + 1, src1, 2);
    // int src2[3] = {1,30,3};
    // char dest[] = "Hello, World!";

    // printf("Before memmove:\n");
    // printf("Destination: %s\n", dest);

    // ft_memmove(dest, src1, 3);
    // printf("After first ft_memmove:\n");
    // printf("Destination: %s\n", dest);

    // ft_memmove(dest, src2, 12);
    // printf("After second ft_memmove:\n");
    // printf("Destination: %d\n", dest[0]);
    printf("dddd\n");
    if (ft_memmove("", "" - 1, 0) == memmove("", "" - 1, 0))
        printf("correct\n");
    else
        printf("wrong\n");
    printf("yes\n");
}

void	check_strlcpy(void)
{
	char	dst1[] = "hello";
	char	dst2[] = "hello";
	char	src[] = "Hello, World!";


	printf("Destination string: %s, Source string: %s\n", dst1, src);
	printf("strlcpy result: %zu, destination string: %s\n", strlcpy(dst1, src, 0), dst1);
	printf("ft_strlcpy result: %zu, destination string: %s\n", ft_strlcpy(dst2, src, 0), dst2);
}

 void check_strlcat(void)
 {
  	size_t n;
  	char dest1[] = "B";
  	char dest2[] = "B";
  	char src[] = "AAAAAAAAA";
  	n = 1;
  	printf("Print destination: %s\n", dest1);
  	printf("Print source: %s\n", src);
  	printf("Concatenate destination and source for %zu -1 characters\n", n);
  	// the resultant string is stored in str1.
  	// ft_strlcat(str1, str2, n);
  	printf("strlcat result: \nPrint destination: %s and return value: %zu\n", dest2, strlcat(dest2, src, n));
  	printf("ft_strlcat result: \nPrint destination: %s and return value: %zu\n", dest1, ft_strlcat(dest1, src, n));
 	// char str[50] = "";

 	// printf("%lu\n", ft_strlcat(str, "world", 0));
 }

void check_toupper(void)
{
    printf("Convert a to uppercase\nft_toupper result: %c\n", ft_toupper('a'));
	printf("toupper result: %c\n", toupper('a'));
}

void	check_tolower(void)
{
    printf("Convert A to lowercase\nft_toupper result: %c\n", ft_tolower('A'));
	printf("toupper result: %c\n", tolower('A'));
}

void	check_strchr(void)
{
    char s[] = "Hello, World!";
    int c = 3;

    printf("s = %s, c = %c, ft_strchr result:%s\n", s, c, ft_strchr(s, c));
    printf("s = %s, c = %c, strchr result:%s\n", s, c, strchr(s, c));
}

void	check_strrchr(void)
{
    char s[] = "Hello, World!";
    int c = 0;

    printf("s = %s, c = %c, ft_strcrhr result:%s\n", s, c, ft_strrchr(s, c));
    printf("s = %s, c = %c, strrchr result:%s\n", s, c, strrchr(s, c));
}

void	check_strncmp(void)
{
	char str1[] = "a/0bcd", str2[] = "a/200bCd", str3[] = "aBcd ";
	unsigned int	n;

	printf("str1 = %s, str2 = %s, str3 = %s.\n", str1, str2, str3);
	n = 3;
	printf("n = %d\n", n);
	// comparing strings str1 and str2
	printf("ft_strncmp(str1, str2, n) = %d\n", ft_strncmp(str1, str2, n));
	printf("strncmp(str1, str2, n) = %d\n", strncmp(str1, str2, n));
	// comparing strings str1 and str3
	printf("ft_strncmp(str1, str3, n) = %d\n", ft_strncmp(str1, str3, n));
	printf("strncmp(str1, str3, n) = %d\n", strncmp(str1, str3, n));
}

void	check_memchr(void)
{
    char src1[] = "Bye";
    char src2[] = "Hello, World!";
    void *result1;
	void *result2;
    int c1 = 101;
    int c2 = 108;

    result1 = ft_memchr(src1, c1, 1);
    printf("Source: %s\nc: %c\nReturn value: %s\n", src1, c1, (unsigned char*)result1);

    result2 = ft_memchr(src2, c2, 3);
	printf("Source: %s\nc: %c\nReturn value: %s\n", src2, c2, (unsigned char*)result2);

	char *src = "/|\x12\xff\x09\x42\2002\42|\\";
	int size = 10;

 	printf("%s\n", ft_memchr(src, '\200', size));

}

void	check_memcmp(void)
{
    char s1[13] = "Hello, World!";
    char s2[14] = "Hello, World!";
    char s3[5] = {'a', 'b', 'c', '\0', 't'};
    char s4[5] = {'a', 'b', 'c', '\0', 'f'};

    printf("s1: %s, s2: %s\nft_memcmp result:%d\n", s1, s2, ft_memcmp(s1, s2, 14));
    printf("s1: %s, s2: %s\nft_strcmp result: %d\n", s3, s4, ft_strncmp(s3, s4, 5));
    printf("ft_memcmp result: %d\n", ft_memcmp(s3, s4, 5));
}

void	check_strnstr(void)
{

	// char * teststd = strnstr(((void *)0), "fake", 3);
	char * testft = ft_strnstr(((void *)0), "fake", 3);
	char str[] = "jhhk";
	char to_find[] = "";
	// printf("strnstr result: %s\n", strnstr(str, to_find, 0));
	// printf("ft_strnstr result: %s\n", ft_strnstr(str, to_find, 0));
	// printf("strnstr result: %s\n", teststd);
	printf("ft_strnstr result: %s\n", testft);
}

void	check_atoi(void)
{
	char	*num1 = "63410682753376583680";
	printf("ft_atoi result:%d\n", ft_atoi(num1));
	printf("atoi result:%d\n", atoi(num1));

	char	*num2 = "9223372036854775806";
	printf("ft_atoi result:%d\n", ft_atoi(num2));
	printf("atoi result:%d\n", atoi(num2));

	char	*num3 = "-9223372036854775808";
	printf("ft_atoi result:%d\n", ft_atoi(num3));
	printf("atoi result:%d\n", atoi(num3));

	char	*num4 = "  -+4983";
	printf("ft_atoi result:%d\n", ft_atoi(num4));
	printf("atoi result:%d\n", atoi(num4));

	char	*num5 = "  -123asd";
	printf("ft_atoi result:%d\n", ft_atoi(num4));
	printf("atoi result:%d\n", atoi(num4));

	char	*num6 = "  +123 3890";
	printf("ft_atoi result:%d\n", ft_atoi(num6));
	printf("atoi result:%d\n", atoi(num6));

	char	*num7 = "9223372036854775808";
	printf("ft_atoi result:%d\n", ft_atoi(num7));
	printf("atoi result:%d\n", atoi(num7));
}

void	check_calloc(void)
{
	int	*str;
	int	i;

	str = ft_calloc(SIZE_MAX, sizeof(int));
	i = 0;
	if (str == NULL)
		printf("Allocation fails!");
	while (i < 3)
	{
		if (str[i] != 0)
			printf("Allocated memory is not \
			filled with bytes of value zero.");
		str[i] = 2;
		printf("%d", str[i]);
		i++;
	}
}

void check_strdup(void)
{
	// char src[] = "HAHAHA \0 tu me vois pas !";

	// printf("%s\n", strdup(src));

	char *str;
	char *tmp = "I malloc so I am.";

	str = ft_strdup(tmp);
}

void	check_substr(void)
{
    char *s = "Hello, World!";

    printf("string: %s", s);
    printf("substring: %s", ft_substr(s, 2, 0));
}

void	check_strjoin(void)
{
    char *s1 = "Hello,";
    char *s2 = "World!";

    printf("s1: %s, s2: %s\n", s1, s2);
    printf("concatenate s1 and s2: %s", ft_strjoin(s1, s2));
}

void	check_strtrim(void)
{
    char *s1 = "   \t  \n\n \t\t  \n\n\n\t\n  ";;
    char *set = " \t\n";

    printf("s1: %s, set: %s\n", s1, set);
    printf("After ft_strtrim: %s", ft_strtrim(s1, set));
}

void	check_split(void)
{
	char *str = "      split       this for   me  !       ";
    char c = ' ';
	char **result = ft_split(str, c);
	int	i = 0;

	printf("%s\n", str);
	while(result[i])
	{
		printf("%s\n", result[i]);
		free(result[i]); // Free individual strings.
        i++;
	}
}

void	check_itoa(void)
{
    char *n1 = ft_itoa(-623);
	char *n2 = ft_itoa(156);
	char *n3 = ft_itoa(-0);
	char *n4 = ft_itoa(-2147483648);

	if (strcmp(n1, "-623"))
        printf("FAIL!\n");
    else
        printf("SUCCESS!\n");
    if (strcmp(n2, "156"))
        printf("FAIL!\n");
    else
        printf("SUCCESS!\n");
    if (strcmp(n3, "0"))
        printf("FAIL!\n");
    else
        printf("SUCCESS!\n");
    if (strcmp(n4, "-2147483648"))
        printf("FAIL!\n");
    else
        printf("SUCCESS!\n");
}

char add(unsigned int n, char c)
{
    c = c + n;
    return (c);
}

void check_strmapi(void)
{
    char *a = "Hello";

    printf("%s", ft_strmapi(a, add));
}

void	minus(unsigned int n, char *s)
{
    *s = *s - n;
}

void	check_striteri(void)
{
    char a[] = "Hello";
    ft_striteri(a, minus);
    printf("%s\n", a);
}


void	check_putstr_fd(void)
{
    char *str = "the cake is a lie !\0I'm hidden lol\r\n";
    ft_putstr_fd(str, 1);
}

void	check_putnbr_fd(void)
{
	printf("print 42: \n");
	ft_putnbr_fd(42, 1);
	printf("\n");

	printf("print -233: \n");
	ft_putnbr_fd(-233, 1);
	printf("\n");

	printf("print 0: \n");
	ft_putnbr_fd(0, 1);
	printf("\n");

	printf("print 8: \n");
	ft_putnbr_fd(8, 1);
	printf("\n");

	printf("print -9: \n");
	ft_putnbr_fd(-9, 1);
	printf("\n");

	printf("print 2147483647: \n");
	ft_putnbr_fd(2147483647, 1);
	printf("\n");

	printf("print -2147483647-1: \n");
    ft_putnbr_fd(-2147483648, 1);
    printf("\n");
}

void check_lstnew(void)
{
    int value = 42;
    t_list *new_node = ft_lstnew(&value);

    if (new_node -> content == &value)
        printf("Sucess!");
    else
        printf("Error!");
    printf("value of new_node->content: %d\n", *(int*)(new_node->content));
}

void check_lstadd_front(void)
{
    int value1 = 42;
    int value2 = 24;
    t_list *node = ft_lstnew(&value1);
    t_list **lst = &node;
    t_list *new_node = ft_lstnew(&value2);
    printf("the value of the first node in list: %d\n", *(int *)((*lst)->content));

    ft_lstadd_front(lst, new_node);
    printf("the value of the first node in list: %d\n", *(int *)((*lst)->content));
}

void check_lstsize(void)
{
    int value1 = 42;
    int value2 = 24;
    t_list *node = ft_lstnew(&value1);
    t_list *new_node = ft_lstnew(&value2);
    node->next = new_node;

    printf("lenth of lst: %d", ft_lstsize(node));
}

void	check_lstlast(void)
{
    int value1 = 42;
    int value2 = 24;
    t_list *node = ft_lstnew(&value1);
    t_list *new_node = ft_lstnew(&value2);
    node->next = new_node;

    printf("last node: %d", *(int *)(ft_lstlast(node)->content));
}

void	check_lstadd_back(void)
{
	t_list *l = ((void *)0);
	t_list *n = ft_lstnew(strdup("OK"));

	ft_lstadd_back(&l, n);
	if (l == n && !strcmp(l->content, "OK"))
	{
		free(l->next);
		free(l);
		printf("success");
	}
	free(l->next);
	free(l);
	printf("fail");
}

// void	check_lstadd_back(void)
// {
//     int value1 = 42;
//     int value2 = 24;
// 	int value3 = 12;
//     t_list *node = ft_lstnew(&value1);
//     t_list *new_node1 = ft_lstnew(&value2);
// 	t_list *new_node2 = ft_lstnew(&value3);
//     printf("the value of the last node in list: \
// 	%d\n",*(int *)((*ft_lstlast(*lst)).content));

//     ft_lstadd_back(&node, new_node1);
//     printf("the value of the last node in list: \
// 	%d\n",*(int *)((*ft_lstlast(*node)).content));

// 	ft_lstadd_back(&node, new_node2);
//     printf("the value of the last node in list: \
// 	%d\n",*(int *)((*ft_lstlast(*node)).content));
// }


void del_node(void *content)
{
    free(content);
}

void check_lstdelone(void)
{
    t_list *node;
    node = malloc(sizeof(t_list));
    node->content = malloc(sizeof(int));
    *(int *)(node->content) = 42;
    t_list *new_node;
    new_node = malloc(sizeof(t_list));
    new_node->content = malloc(sizeof(int));
    *(int *)(new_node->content) = 24;
    node->next = new_node;

    printf("the value of the first node in list: %d\n", *(int *)((*node).content));
    printf("the value of the second node in list: %d\n", *(int *)((*(node->next)).content));

    ft_lstdelone(node, del_node);
    printf("the value of the last node in list: %d\n", *(int *)((*(new_node)).content));
}


void check_lstclear(void)
{
	t_list *node;
	node = malloc(sizeof(t_list));
	node->content = malloc(sizeof(int));
	*(int *)(node->content) = 42;
	t_list *new_node1;
	new_node1 = malloc(sizeof(t_list));
	new_node1->content = malloc(sizeof(int));
	*(int *)(new_node1->content) = 24;
	node->next = new_node1;
	t_list *new_node2;
	new_node2 = malloc(sizeof(t_list));
	new_node2->content = malloc(sizeof(int));
	*(int *)(new_node2->content) = 55;
	new_node2->next = NULL;
	new_node1->next = new_node2;

	printf("the value of the first node in list: %d\n", *(int *)((*node).content));
	printf("the value of the second node in list: %d\n", *(int *)((*(node->next)).content));
	printf("the value of the third node in list: %d\n", *(int *)((*(new_node1->next)).content));

	ft_lstclear(&node, del_node);
	if (!node)
		printf("SUCCESS!\n");
}

void print_node(void *content)
{
	printf("the value of the node: %s\n", (char*)content);
}

void check_lstiter(void)
{
	t_list *node1 = ft_lstnew("Hello");
	t_list *node2 = ft_lstnew("world");
	t_list *node3 = ft_lstnew("!");
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	printf("the value of the first node in list: %s\n", (char *)((*node1).content));
	printf("the value of the second node in list: %s\n", (char *)((*node2).content));
	printf("the value of the third node in list: %s\n", (char *)((*node3).content));

	ft_lstiter(node1, print_node);
}

void	*node_add2(void *content)
{
	*(int*)content = *(int*)content + 2;
	return (content);
}

void	check_lstmap(void)
{
	t_list *head;

	head = NULL;
	int	*num_1 = malloc(sizeof(int));
	*num_1 = 42;

	int	*num_2 = malloc(sizeof(int));
	*num_2 = 24;

	int	*num_3 = malloc(sizeof(int));
	*num_3 = 12;

	ft_lstadd_back(&head,  ft_lstnew(num_1));
	ft_lstadd_back(&head,  ft_lstnew(num_2));
	ft_lstadd_back(&head,  ft_lstnew(num_3));

	t_list *temp;
	temp = head;
	while (temp != NULL)
	{
		printf("the value of the node in origin list: %d\n", *((int *)temp->content));
		temp = temp->next;
	}
	t_list	*new_lst = ft_lstmap(head, node_add2, del_node);

	while (new_lst != NULL)
	{
		printf("the value of the node in new list: %d\n", *((int *)new_lst->content));
		new_lst = new_lst->next;
	}
}

int	main(void)
{
	printf("--------------------Test Start--------------------\n\n");
	printf("--------------------ft_isalpha--------------------\n");
	check_isalpha();
	printf("--------------------ft_isdigit--------------------\n");
	check_isdigit();
	printf("--------------------ft_isalnum--------------------\n");
	check_isalnum();
	printf("--------------------ft_isascii--------------------\n");
	check_isascii();
	printf("--------------------ft_isprint--------------------\n");
	check_isprint();
	printf("---------------------ft_strlen---------------------\n");
	check_strlen();
	printf("---------------------ft_memset---------------------\n");
	check_memset();
	printf("---------------------ft_memcpy---------------------\n");
	check_memcpy();
	printf("---------------------ft_bzero---------------------\n");
	check_bzero();
	printf("---------------------ft_memmove---------------------\n");
	check_memmove();
	printf("---------------------ft_strlcpy---------------------\n");
	check_strlcpy();
	printf("---------------------ft_strlcat---------------------\n");
	check_strlcat();
	printf("---------------------ft_toupper---------------------\n");
	check_toupper();
	printf("---------------------ft_tolower---------------------\n");
	check_tolower();
	printf("---------------------ft_strchr---------------------\n");
	check_strchr();
	printf("---------------------ft_strrchr---------------------\n");
	check_strrchr();
	printf("---------------------ft_strncmp---------------------\n");
	check_strncmp();
	printf("---------------------ft_memchr---------------------\n");
	check_memchr();
	printf("---------------------ft_memcmp---------------------\n");
	check_memcmp();
	printf("---------------------ft_strnstr---------------------\n");
	check_strnstr();
	printf("---------------------ft_atoi---------------------\n");
	check_atoi();
	printf("---------------------ft_calloc---------------------\n");
	check_calloc();
	printf("---------------------ft_strdup---------------------\n");
	check_strdup();
	printf("---------------------ft_substr---------------------\n");
	check_substr();
	printf("---------------------ft_strjoin---------------------\n");
	check_strjoin();
	printf("---------------------ft_strtrim---------------------\n");
	check_strtrim();
	printf("---------------------ft_split---------------------\n");
	check_split();
	printf("---------------------ft_itoa---------------------\n");
	check_itoa();
	printf("---------------------ft_strmapi---------------------\n");
	check_strmapi();
	printf("---------------------ft_striteri--------------------\n");
	check_striteri();
	//check_putchar_fd();
	printf("---------------------ft_putstr_fd---------------------\n");
	check_putstr_fd();
	//check_putendl_fd();
	printf("---------------------ft_putnbr_fd---------------------\n");
	check_putnbr_fd();
	printf("---------------------ft_lstnew---------------------\n");
	check_lstnew();
	printf("---------------------ft_lstadd_front---------------------\n");
	check_lstadd_front();
	printf("---------------------ft_lstnew---------------------\n");
	check_lstsize();
	printf("---------------------ft_lstlast---------------------\n");
	check_lstlast();
	//check_strcmp();
	printf("---------------------ft_lstdelone---------------------\n");
	check_lstdelone();
	printf("---------------------ft_lstclear---------------------\n");
	check_lstclear();
	printf("---------------------ft_lstiter---------------------\n");
	check_lstiter();
	printf("---------------------ft_lstmap---------------------\n");
	check_lstmap();
}
