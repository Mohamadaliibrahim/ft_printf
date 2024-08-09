#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack	*create_stack_from_args(int ac, char **av)
{
	t_stack	*stack;
	t_node	*new_node;
	int		i;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	i = ac - 1;
	while (i >= 1)
	{
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			return (NULL);
		new_node->value = atoi(av[i]);
		new_node->next = stack->top;
		if (stack->top)
			stack->top->prev = new_node;
		stack->top = new_node;
		stack->size++;
		i--;
	}
	return (stack);
}

