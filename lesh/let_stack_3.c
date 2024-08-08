#include "push_swap.h"

void	sort_five1(t_stack **a, t_stack **b)
{
	int	min;
	int	index;

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
	{
		rra(a);
		rra(a);
	}
	else if (index == 4)
		rra(a);
	pb(a, b);
}

void	sort_five2(t_stack **a, t_stack **b)
{
	int	min;
	int	index;

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
}

void	sort_five(t_stack **a, t_stack **b)
{
	if (!a || !*a || !(*a)->next || stack_is_sorted(*a))
		return ;

	sort_five1(a, b);
	sort_five2(a, b);

	sort_three(a);
	pa(a, b);
	pa(a, b);
}
