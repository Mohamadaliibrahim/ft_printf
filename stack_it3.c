#include "push_swap.h"

static void	cost_analysis_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

static void	set_targert_a(t_stack *a, t_stack *b)
{
	t_stack	*currect_b;
	t_stack	*target_node;
	long	best_match;

	while (a)
	{
		best_match = LONG_MIN;
		currect_b = b;
		while (currect_b)
		{
			if (currect_b->nbr < a->nbr
				&& currect_b->nbr > best_match)
			{
				best_match = currect_b->nbr;
				target_node = currect_b;
			}
			currect_b = currect_b->next;
		}
		if (best_match == LONG_MIN)
			a->target_node = target_node;
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	init_node_a(t_stack *a, t_stack *b)
{
	currnet_index(a);
	currnet_index(b);
	set_targert_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

void	currnet_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a) - 1;
	if (len_a > 3 && !stack_stored(*a))
		pb(b, a, false);
	if (len_a > c && !stack_stored(*a))
		pb(b, a, false);
	while (len_a > 3 && !stack_stored(*a))
	{
		init_node_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_node_b(*a, *b);
		move_b_to_a(a, b);
	}
	currnet_index(*a);
	min_to_top(a);
}
// stop !!