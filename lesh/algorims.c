#include "push_swap.h"

int	get_cost_it(t_stack *b, int target)
{
	t_stack	*tmp;
	int		i;

	tmp = b;
	i = 0;
	while (tmp)
	{
		if (target == b->data)
			break ;
		i++;
	}
}

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

int	get_cost(t_stack *x, int position, int size)
{
	if (position > stack_len(x) / 2)
		return (stack_len(x) - position);
	return (position);
}

void	calculate_min_cost(t_stack *a, t_stack *b)
{
	t_node	*current_a;
	t_node	*current_b;
	int		min_cost;
	int		best_position_a;
	int		best_position_b;
	int		cost_a;
	int		cost_b;
	int		target;
	int		pos_a;
	int		pos_b;

	min_cost = INT_MAX;
	best_position_a = 0;
	best_position_b = 0;
	pos_a = 0;
	current_a = a->top;
	while (current_a)
	{
		target = a_to_b_find_target(b, current_a->value);
		pos_b = 0;
		current_b = b->top;
		while (current_b)
		{
			if (current_b->value == target)
				break ;
			pos_b++;
			current_b = current_b->next;
		}
		cost_a = get_cost(a, pos_a, a->size);
		cost_b = get_cost(b, pos_b, b->size);
		if (cost_a + cost_b < min_cost)
		{
			min_cost = cost_a + cost_b;
			best_position_a = pos_a;
			best_position_b = pos_b;
		}
		pos_a++;
		current_a = current_a->next;
	}
}
