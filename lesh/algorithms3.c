#include "push_swap.h"

int	find_median_index(int size)
{
	if (size % 2 == 0)
		return (size / 2);
	else
		return (size / 2 + 1);
}

void	push_with_min_cost(t_stack *a, t_stack *b)
{
	t_cost	cost;

	min_cost_b_to_a(a, b);
	push_with_min_cost1(a, &cost);
	push_with_min_cost2(a, &cost);
	push_with_min_cost3(b, &cost);
	pa(&a, &b);
}

void	push_with_min_cost1(t_stack *a, t_cost *cost)
{
	int	median_index;

	median_index = find_median_index(a->size);
	if (cost->best_a > median_index)
	{
		while (cost->best_a < a->size)
		{
			rra(&a);
			cost->best_a++;
		}
	}
	else
	{
		while (cost->best_a > 0)
		{
			ra(&a);
			cost->best_a--;
		}
	}
}

void	push_with_min_cost2(t_stack *a, t_cost *cost)
{
	int	median_index;

	median_index = find_median_index(a->size);
	if (cost->best_a > median_index)
	{
		while (cost->best_a < a->size)
		{
			rra(&a);
			cost->best_a++;
		}
	}
	else
	{
		while (cost->best_a > 0)
		{
			ra(&a);
			cost->best_a--;
		}
	}
}

void	push_with_min_cost3(t_stack *b, t_cost *cost)
{
	if (cost->best_b > b->size / 2)
	{
		while (cost->best_b < b->size)
		{
			rrb(&b);
			cost->best_b++;
		}
	}
	else
	{
		while (cost->best_b > 0)
		{
			rb(&b);
			cost->best_b--;
		}
	}
}
//stop!