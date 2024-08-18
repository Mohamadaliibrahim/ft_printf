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
	int	stack_size;

	stack_size = stack_len(*a);
	min_index = find_min_index(*a);
	median_line = stack_size / 2;
	if (min_index > median_line)
		while (min_index++ < stack_size)
			rra(a);
	else
	{
		while (min_index-- > 0)
		{
			ra(a);
			printf("here3\n");
		}
	}
}

void	stack_3_and_b(t_stack **a, t_stack **b)
{
	if (stack_len(*a) == 3 && !stack_is_sorted(*a))
		sort_three(a);
	push_to_target(a, b);
	if (!stack_is_sorted(*a))
		rotate_to_min(a);
}

void	push_swap_it(t_stack **a, t_stack **b)
{
	pb(a, b);
	if (stack_len(*a) == 3)
		stack_3_and_b(a, b);
	if (stack_len(*a) > 3)
		pb(a, b);
	if (stack_len(*a) == 3)
		stack_3_and_b(a, b);
	else
	{
		while (stack_len(*a) > 3)
			push_min_cost(a, b);
		sort_three(a);
		stack_3_and_b(a, b);
	}
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (-1);
	ft_check_args(ac, av);
	a = create_stack_from_args(ac, av);
	b = NULL;
	if (a == NULL)
	{
		ft_error("Error");
		return (1);
	}
	if (stack_is_sorted(a))
		finish_program(a, b);
	if (stack_len(a) == 2)
		sa(&a);
	if (stack_len(a) == 3)
		sort_three(&a);
	else
	{
		push_swap_it(&a, &b);
	}
	// if (stack_is_sorted(a))
	// 	ft_printf("great");
	// else
	// 	ft_printf("NO");
	free_stack(a);
	free_stack(b);
	return (0);
}
