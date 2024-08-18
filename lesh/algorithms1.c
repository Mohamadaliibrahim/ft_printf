#include "push_swap.h"

t_stack *set_target_nodes_b(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *sa;
    t_stack *sb;
    t_stack *closest;

    sb = stack_b;
    while (sb)
    {
        sa = stack_a;
        closest = NULL;
        while (sa)
        {
            if ((sa->data > sb->data) && (!closest || sa->data < closest->data))
                closest = sa;
            sa = sa->next;
        }
        if (closest)
            sb->target_node = closest;
        else
            sb->target_node = find_smallest(stack_a);
        sb = sb->next;
    }
    return (stack_b);
}

void move_b_to_a(t_stack **a, t_stack **b)
{
    bring_on_top(a, (*b)->target_node, 'a');
    pa(a, b);  // Replace 'ps' with the correct operation, in this case, 'pa'
}

void init_node_b(t_stack **a, t_stack **b)
{
    current_index(*a);
    current_index(*b);
    *b = set_target_nodes_b(*a, *b);
}

t_stack *set_cheapest(t_stack *stack)
{
    t_stack *s;
    t_stack *cost;

    s = stack;
    cost = stack;
    while (s)
    {
        if (cost->cost > s->cost)
            cost = s;
        s = s->next;
    }
    cost->cheapest = true;
    return (stack);
}

t_stack *cost_analyst(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *s;
    int size_a;
    int size_b;

    s = stack_a;
    size_a = stack_len(stack_a);  // Assuming you have a function `stack_len` to get the stack size
    size_b = stack_len(stack_b);
    while (s)
    {
        s->cost = s->index;
        if (!(s->above_median))
            s->cost = size_a - (s->index);
        if (s->target_node->above_median)
            s->cost += s->target_node->index;
        else
            s->cost += size_b - (s->target_node->index);
        s = s->next;
    }
    return (stack_a);
}

t_stack *find_max_node(t_stack *stack)
{
    t_stack *max_node = stack;

    while (stack)
    {
        if (stack->data > max_node->data)
            max_node = stack;
        stack = stack->next;
    }
    return max_node;
}

t_stack *set_target_nodes_a(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *sa;
    t_stack *sb;
    t_stack *closest;

    sa = stack_a;
    while (sa)
    {
        sb = stack_b;
        closest = NULL;
        while (sb)
        {
            if (sa->data > sb->data && (!closest || sb->data > closest->data))
                closest = sb;
            sb = sb->next;
        }
        if (closest)
            sa->target_node = closest;
        else
            sa->target_node = find_max_node(stack_b);  // Use 'find_max_value' if 'find_biggest' doesn't exist
        sa = sa->next;
    }
    return (stack_a);
}
