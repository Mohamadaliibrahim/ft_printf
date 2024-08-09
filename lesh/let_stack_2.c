#include "push_swap.h"

int find_min_value(t_stack *a)
{
	int min;
	t_node *current;

	if (!a || !a->top)
		return (INT_MAX); // Return the maximum int value if the stack is empty.

	current = a->top;
	min = current->value; // Start with the first node's value as the minimum.
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

t_node *find_index(t_stack *a, int value)
{
    t_node *current = a->top;

    while (current)
    {
        if (current->value == value)
            return current;
        current = current->next;
    }
    return NULL;
}

void sort_four(t_stack **a, t_stack **b)
{
	int min;
	t_node *min_node;

	if (!a || !*a || !(*a)->top || stack_is_sorted(*a))
		return ;

	min = find_min_value(*a);
	min_node = find_index(*a, min);

	if (min_node == (*a)->top->next) // If min is in position 1
		ra(a);
	else if (min_node == (*a)->top->next->next) // If min is in position 2
	{
		ra(a);
		ra(a);
	}
	else if (min_node == (*a)->top->prev) // If min is in position 3
		rra(a);

	pb(a, b);
	sort_three(a);
	pa(a, b);
}
