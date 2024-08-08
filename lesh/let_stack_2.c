#include "push_swap.h"

int	find_min_value(t_stack *a)
{
	int	min;

	min = a->data;
	while (a)
	{
		if (a->data < min)
			min = a->data;
		a = a->next;
	}
	return (min);
}

int	find_index(t_stack *a, int value)
{
	int	index;

	index = 0;
	while (a)
	{
		if (a->data == value)
			return (index);
		index++;
		a = a->next;
	}
	return (-1);
}

void	sort_four(t_stack **a, t_stack **b)
{
	int		min;
	int		index;

	if (!a || !*a || !(*a)->next || stack_is_sorted(*a))
		return ;
	min = find_min_value(*a);
	index = find_index(*a, min);
	if (index == 1)
		ra(a);
	else if (index == 2)
	{
		ra(a);
		ra(a);
	}
	else if (index == 3)
		rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}
