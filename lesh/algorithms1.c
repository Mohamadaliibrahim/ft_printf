#include "push_swap.h"

void	min_cost(t_stack *a, t_stack *b)
{
	t_cost	cost;

	min_cost1(a, b, &cost);
	min_cost4(a, cost.best_a); // Pass a
	min_cost5(b, cost.best_b); // Pass b
	pb(&a, &b); // Pass &a and &b (this is correct for pb)
}


void	min_cost1(t_stack *a, t_stack *b, t_cost *cost)
{
	t_node	*current_a;

	cost->min_cost = INT_MAX;
	cost->pos_a = 0;
	current_a = a->top;
	while (current_a)
	{
		min_cost2(a, b, current_a, cost);
		cost->pos_a++;
		current_a = current_a->next;
	}
}

void	min_cost2(t_stack *a, t_stack *b, t_node *current_a, t_cost *cost)
{
	int			target;
	int			cost_a;
	int			cost_b;
	t_calc_args	args;

	target = a_to_b_find_target(b, current_a->value);
	args.a = a; // Initialize args.a
	args.b = b;
	args.target = target;
	args.pos_a = cost->pos_a;

	min_cost3(&args, &cost_a, &cost_b);
	if (cost_a + cost_b < cost->min_cost)
	{
		cost->min_cost = cost_a + cost_b;
		cost->best_a = cost->pos_a;
		cost->best_b = cost_b;
	}
}



void	min_cost3(t_calc_args *args, int *cost_a, int *cost_b)
{
	t_node	*current_b;
	int		pos_b;

	pos_b = 0;
	current_b = args->b->top;
	while (current_b)
	{
		if (current_b->value == args->target)
			break ;
		pos_b++;
		current_b = current_b->next;
	}
	*cost_a = get_cost(args->a, args->pos_a);
	*cost_b = get_cost(args->b, pos_b);
}

void	min_cost4(t_stack *a, int best_position_a)
{
	if (best_position_a > a->size / 2)
	{
		while (best_position_a < a->size)
		{
			rra(&a); // Pass a as t_stack **
			best_position_a++;
		}
	}
	else
	{
		while (best_position_a > 0)
		{
			ra(&a); // Pass a as t_stack **
			best_position_a--;
		}
	}
}


//stop!