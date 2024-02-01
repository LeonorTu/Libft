#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack {
    int value;
    struct s_stack *next;
} t_stack;

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*first_node;

	if (!*src)
		return ;
	first_node = *src;
	*src = (*src)->next;
	if (*dst)
	{
		first_node->next = *dst;
		*dst = first_node;
	}
	else
	{
		*dst = first_node;
		first_node->next = NULL;
	}
}

t_stack	*last_node(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}

void	rotate_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = last_node(stack);
	(*stack)->next = temp;
	*stack = temp->next;
	temp->next = NULL;
}

void	ra(t_stack **a)
{
	rotate_stack(a);
	write(1, "ra\n", 3);
}

t_stack *createNode(int value) {
    t_stack *newNode = (t_stack *)malloc(sizeof(t_stack));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void printList(t_stack *head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Creating linked list a with values 9, 41, 45, 78
    t_stack *a = NULL;
    a = (t_stack*)malloc(sizeof(t_stack));
    a->value = 78;
    a->next = (t_stack*)malloc(sizeof(t_stack));
    a->next->value = 45;
    a->next->next = (t_stack*)malloc(sizeof(t_stack));
    a->next->next->value = 41;
    a->next->next->next = (t_stack*)malloc(sizeof(t_stack));
    a->next->next->next->value = 9;
    a->next->next->next->next = NULL;

    t_stack **a1 = &a;

    // Creating linked list b with values 4, 11
    t_stack *b = NULL;
    b = (t_stack*)malloc(sizeof(t_stack));
    b->value = 11;
    b->next = (t_stack*)malloc(sizeof(t_stack));
    b->next->value = 4;
    b->next->next = NULL;

    t_stack **b1 = &b;
    printf("Initial state:\n");
    printf("List a: ");
    printList(*a1);
    printf("List b: ");
    printList(*b1);

    // Test pa function
    pa(a1, b1);
    ra(a1);
    ra(a1);
    pa(a1, b1);

    printf("\nAfter ra:\n");
    printf("List a: ");
    printList(*a1);
    printf("List b: ");
    printList(*b1);
    // Test pa function
    //pa(a1, b1);

    // printf("\nAfter ra:\n");
    // printf("List a: ");
    // printList(*a1);
    // printf("List b: ");
    // printList(*b1);
    // if (b1 == NULL)
    //     printf("haha");

    // Free allocated memory
    // Make sure to implement a function to free the linked list nodes

    return 0;
}
