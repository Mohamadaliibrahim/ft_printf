#include "push_swap.h"

void	finish_program(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	exit(0);
}

void	rotate_to_min(t_stack **a)
{
	int	min_index;
	int	median_line;

	min_index = find_min_value(*a);
	median_line = stack_len(*a) / 2;
	if (min_index > median_line)
		while (min_index++ < stack_len(*a))
			rra(a);
	else
		while (min_index-- > 0)
			ra(a);
}

void	stack_3_and_b(t_stack **a, t_stack **b)
{
	if (stack_len(*a) == 3 && !stack_is_sorted(*a))
		sort_three(a);
	
	if (stack_len(*a) > 3)
		pb(a, b);

	if (stack_len(*a) == 3)
	{
		sort_three(a);
		rotate_to_min(a);
	}

	push_to_target(a, b);
}


void push_swap_it(t_stack **a, t_stack **b)
{
    pb(a, b);
    if (stack_len(*a) == 3)
        stack_3_and_b(a, b);
    pb(a, b);
    if (stack_len(*a) == 3)
        stack_3_and_b(a, b);
    else
		ft_printf("hello");
}

int main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*t;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (-1);
	ft_check_args(ac, av);
	a = create_stack_from_args(ac, av);
	b = init_stack();
	if (a == NULL || b == NULL)
	{
		ft_error("Error: Failed to initialize stacks.");
		return (1);
	}
	if (stack_is_sorted(a))
		finish_program(a, b);
	if (stack_len(a) == 2)
		sa(&a);
	ft_printf ("ade:%d\n", stack_len(a));
	if (stack_len(a) == 3)
		sort_three(&a);
	else
	{
		push_swap_it(&a, &b);
	}
	t = a;
	ft_printf("Sorted stack:\n");
	while (t)
	{
		ft_printf("%d\n", t->data);  // Debug print
		t = t->next;
	}
	free_stack(a);
	free_stack(b);
	return (0);
}

