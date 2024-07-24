#include "push_swap.h"

t_stack	*init_stack()
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->top = NULL;
	return (stack);
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
}

int	pop(t_stack *stack)
{
	if (stack->top == NULL)
	{
		return (-1);
	}
	int		value;
	t_node	*temp;

	temp = stack->top;
	value = temp->value;
	stack->top = stack->top->next;
	free(temp);
	return (value);
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL) 
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}