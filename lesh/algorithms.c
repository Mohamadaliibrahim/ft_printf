#include "push_swap.h"

int	a_to_b_find_target(t_stack *b, int value)
{
	t_node	*current;
	int		target;
	int		max;

	current = b->top;
	target = INT_MIN;
	max = INT_MIN;
	while (current)
	{
		if (current->value < value && current->value > target)
			target = current->value;
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	if (target == INT_MIN)
		return (max);
	return (target);
}

int	get_cost(t_stack *x, int position)
{
	if (position > x->size / 2)
		return (x->size - position);
	return (position);
}

t_node	*b_to_a_find_target(t_stack *a, int b_value)
{
	t_node	*current;
	t_node	*target;
	int		min_value;

	current = a->top;
	target = NULL;
	min_value = find_min_value(a);
	while (current)
	{
		if (current->value > b_value)
		{
			if (!target || current->value < target->value)
				target = current;
		}
		current = current->next;
	}
	if (!target)
		target = find_index(a, min_value);
	return (target);
}

void	assign_targets(t_stack *a, t_stack *b)
{
	t_node	*current_b;

	current_b = b->top;
	while (current_b)
	{
		current_b->target_node = b_to_a_find_target(a, current_b->value);
		current_b = current_b->next;
	}
}
