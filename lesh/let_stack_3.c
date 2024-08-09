// Assuming find_index should return an int (the index of the node in the stack):
#include "push_swap.h"

// Function to find the index of a node with the given value in the stack
int find_index1(t_stack *a, int value)
{
    t_node *current;
    int index;

    current = a->top;
    index = 0;

    // Traverse the stack to find the value
    while (current != NULL)
    {
        if (current->value == value)
            return index;
        current = current->next;
        index++;
    }

    // If the value is not found, return -1 or an appropriate error code
    return -1;
}


void sort_five1(t_stack **a, t_stack **b)
{
    int min;
    int index;

    min = find_min_value(*a);
    index = find_index1(*a, min);  // This should return an int now
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

void sort_five2(t_stack **a, t_stack **b)
{
    int min;
    int index;

    min = find_min_value(*a);
    index = find_index1(*a, min);  // This should return an int now
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

void sort_five(t_stack **a, t_stack **b)
{
    if (!a || !*a || !(*a)->top->next || stack_is_sorted(*a))
        return ;
    sort_five1(a, b);
    sort_five2(a, b);
    sort_three(a);
    pa(a, b);
    pa(a, b);
}
