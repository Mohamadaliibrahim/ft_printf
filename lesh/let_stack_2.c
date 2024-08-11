#include "push_swap.h"

int	find_min_value(t_stack *a)
{
	int		min;
	t_stack	*current;

	if (!a)
		return (INT_MAX);

	current = a;
	min = current->data;
	while (current)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	return (min);
}
