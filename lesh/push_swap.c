#include "push_swap.h"

int main(int ac, char *av[])
{
    t_stack *a;
    t_stack *b;

    if (ac == 1 || (ac == 2 && !av[1][0]))
        return (-1);

    ft_check_args(ac, av);

    a = create_stack_from_args(ac, av);
    b = init_stack();  // Initialize stack `b`

    if (a == NULL || b == NULL)  // Check if either stack failed to initialize
    {
        ft_error("Error: Failed to initialize stacks.");
        return (1);
    }

    if (stack_is_sorted(a))
    {
        free_stack(a);
        free_stack(b);  // Free both stacks
        return (0);
    }

    if (stack_len(a) == 2)
        sa(&a);
    else if (stack_len(a) == 3)
        sort_three(&a);
    else if (stack_len(a) == 4)
        sort_four(&a, &b);
    else if (stack_len(a) == 5)
        sort_five(&a, &b);
    else
    {
        assign_targets(a, b);
        sort_b_to_a(a, b);
        move_min_to_top(a);
    }

    // Debug: Print the stack after sorting
    t_node *t = a->top;
    ft_printf("Sorted stack:\n");
    while (t)
    {
        ft_printf("%d\n", t->value);
        t = t->next;
    }

    free_stack(a);
    free_stack(b);
    return (0);
}
