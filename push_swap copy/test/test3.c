#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	int data;
	struct stack *next;
} t_stack;

// void free_stack(t_stack **stack)
// {
// 	if (!stack || !(*stack))
// 		return;
// 	free_stack(&((*stack)->next));
// 	free(*stack);
// 	*stack = NULL;
// }

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void print_stack(t_stack *stack)
{
	while (stack != NULL) {
		printf("%d ", stack->data);
		stack = stack->next;
	}
	printf("\n");
}

int main()
{
	t_stack *stack = NULL;
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->data = 5;
	stack->next = (t_stack *)malloc(sizeof(t_stack));
	stack->next->data = 10;
	stack->next->next = NULL;

	printf("Before freeing the stack:");
	print_stack(stack);

	free_stack(&stack);

	printf("After freeing the stack:");
	print_stack(stack);

	return 0;
}

