#include "push_swap.h"

t_stack *push_swap(t_stack **stack_a, t_stack **stack_b, int size_a)
{
    if (size_a-- > 3 && !stack_is_sorted(*stack_a))
        pb(stack_a, stack_b);
    if (size_a-- > 3 && !stack_is_sorted(*stack_a))
        pb(stack_a, stack_b);
    while (size_a-- > 3 && !stack_is_sorted(*stack_a))
    {
        init_node_a(stack_a, stack_b);
        move_a_to_b(stack_a, stack_b);
    }
    sort_three(stack_a);
    while (*stack_b)
    {
        init_node_b(stack_a, stack_b);
        move_b_to_a(stack_a, stack_b);
    }
    current_index(*stack_a);
    while ((*stack_a)->data != find_smallest(*stack_a)->data)
    {
        if (find_smallest(*stack_a)->above_median)
            ra(stack_a);
        else
            rra(stack_a);
    }
    return (*stack_a);
}


t_stack	*get_cheapest(t_stack *stack)
{
	t_stack	*s;

	s = stack;
	while (s)
	{
		if (s->cheapest)
			return (s);
		s = s->next;
	}
	return (stack);
}

void	bring_on_top(t_stack **stack, t_stack *desired_node, char stack_name)
{
	while (*stack != desired_node)
	{
		if (desired_node->above_median)
		{
			if (stack_name == 'a')
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if (stack_name == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}



void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
	{
		while (*b != cheapest_node->target_node && *a != cheapest_node)
			rr(a, b);
		current_index(*a);
		current_index(*b);
	}
	else if (!cheapest_node->above_median
		&& !cheapest_node->target_node->above_median)
	{
		while (*b != cheapest_node->target_node && *a != cheapest_node)
			rrr(a, b);
		current_index(*a);
		current_index(*b);
	}
	bring_on_top(a, cheapest_node, 'a');
	bring_on_top(b, cheapest_node->target_node, 'b');
	pb(a, b);
}

void	init_node_a(t_stack **a, t_stack **b)
{
	current_index(*a);
	current_index(*b);
	*a = set_target_nodes_a(*a, *b);
	*a = cost_analyst(*a, *b);
	*a = set_cheapest(*a);
}
