#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = 0;
	stack->cost = 0;
	stack->target = NULL;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

int	stack_is_empty(t_stack *stack)
{
	return (stack == NULL);
}


