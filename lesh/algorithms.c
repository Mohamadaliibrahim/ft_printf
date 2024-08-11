#include "push_swap.h"

int	a_to_b_find_target(t_stack *b, int value)
{
	t_stack	*current;
	int		target;
	int		max;

	current = b;
	target = INT_MIN;
	max = INT_MIN;
	while (current)
	{
		if (current->data < value && current->data > target)
			target = current->data;
		if (current->data > max)
			max = current->data;
		current = current->next;
	}
	if (target == INT_MIN)
		return (max);
	return (target);
}

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

#include "push_swap.h"

int find_target_index(t_stack *a, int b_data)
{
	t_stack *current;
	int target_index;
	int closest_max;
	int i;

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

int find_min_index(t_stack *a)
{
	t_stack *current;
	int min;
	int min_index;
	int i;

	current = a;
	min = current->data;
	min_index = 0;
	i = 0;
	while (current)
	{
		if (current->data < min)
		{
			min = current->data;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	return (min_index);
}

void push_to_target(t_stack **a, t_stack **b)
{
	int target_index;
	int median_line;
	int b_data;

	while (*b)
	{
		b_data = (*b)->data;
		target_index = find_target_index(*a, b_data);
		median_line = stack_len(*a) / 2;
		perform_rotations(a, target_index, median_line);
		pa(a, b);
	}
}
