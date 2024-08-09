#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (-1);
	ft_check_args(ac, av);
	a = create_stack_from_args(ac, av);
	if (stack_is_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	if (stack_len(a) == 3)
	{
		sort_three(&a);
	}
	else if (stack_len(a) == 4)
	{
		sort_four(&a, &b);
	}
	else if (stack_len(a) == 5)
	{
		sort_five(&a, &b);
	}
	else
	{
		assign_targets(a, b);
		sort_b_to_a(a, b);
		move_min_to_top(a);
	}
	free_stack(a);
	free_stack(b);
	return (0);
}
