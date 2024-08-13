#include "push_swap.h"

void	perform_rotations(t_stack **a, int target_index, int median_line)
{
	if (target_index <= median_line)
	{
		while (target_index-- > 0)
			ra(a);
	}
	else
	{
		while (target_index++ < stack_len(*a))
			rra(a);
	}
}

int	find_target_index(t_stack *a, int b_data)
{
	t_stack	*current;
	int		target_index;
	int		closest_max;
	int		i;

	current = a;
	target_index = 0;
	closest_max = INT_MAX;
	i = 0;
	while (current)
	{
		if (current->data > b_data && current->data < closest_max)
		{
			closest_max = current->data;
			target_index = i;
		}
		current = current->next;
		i++;
	}
	if (closest_max == INT_MAX)
		return (find_min_index(a));
	return (target_index);
}

int	find_min_index(t_stack *a)
{
	int		min;
	int		index;
	int		min_index;
	t_stack	*current;

	if (!a)
		return (-1);

	current = a;
	min = current->data;
	min_index = 0;
	index = 0;
	while (current)
	{
		if (current->data < min)
		{
			min = current->data;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	return (min_index);
}

void	push_to_target(t_stack **a, t_stack **b)
{
	int	target_index;
	int	median_line;
	int	b_data;

	while (*b)
	{
		b_data = (*b)->data;
		target_index = find_target_index(*a, b_data);
		median_line = stack_len(*a) / 2;
		perform_rotations(a, target_index, median_line);
		pa(a, b);
	}
}
