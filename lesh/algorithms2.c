#include "push_swap.h"

void	min_cost5(t_stack *b, int best_position_b)
{
	if (best_position_b > b->size / 2)
	{
		while (best_position_b < b->size)
		{
			rrb(&b);
			best_position_b++;
		}
	}
	else
	{
		while (best_position_b > 0)
		{
			rb(&b);
			best_position_b--;
		}
	}
}

void	min_cost_b_to_a(t_stack *a, t_stack *b)
{
	t_cost	cost;

	min_cost1(a, b, &cost);
	min_cost4(a, cost.best_a);
	min_cost5(b, cost.best_b);
	pa(&a, &b);
}

void	sort_b_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		push_with_min_cost(a, b);
	}
}

void	move_min_to_top(t_stack *a)
{
	int		min_value;
	int		min_position;
	int		median;

	min_value = find_min_value(a);
	min_position = find_index(a, min_value)->index;
	median = a->size / 2;
	if (min_position <= median)
	{
		while (min_position > 0)
		{
			ra(&a);
			min_position--;
		}
	}
	else
	{
		while (min_position < a->size)
		{
			rra(&a);
			min_position++;
		}
	}
}

t_stack *init_stack(void)
{
    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}
