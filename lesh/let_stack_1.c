#include "push_swap.h"

t_stack	*create_stack_from_args(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*new_node;
	int		i;

	stack = NULL;
	i = ac - 1;
	while (i >= 1)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->data = atoi(av[i]);
		new_node->next = stack;
		stack = new_node;
		i--;
	}
	return (stack);
}