#include "push_swap.h"
#include <stdio.h>

t_stack	*last_node(t_stack **stack)
{
	while ((*stack)->next)
		*stack = (*stack)->next;
	return (*stack);
}
void rotate_stack(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	*stack = last_node(stack);
	(*stack)->next = temp;
	*stack = temp->next;
	temp->next = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;

	a = malloc(sizeof(t_stack));
	a->value = 32;
	a->next = NULL;

	b = malloc(sizeof(t_stack));
	b->value = 44;
	b->next = a;

	c = malloc(sizeof(t_stack));
	c->value = 78;
	c->next = b;

	// while (c != NULL) //
	// {
	// 	printf("the value of the node: %d\n", c->value);
	// 	c = c->next;
	// }

	rotate_stack(&c);
	while (c != NULL) //
	{
		printf("the value of the node: %d\n", c->value);
		c = c->next;
	}

	return (0);
}
