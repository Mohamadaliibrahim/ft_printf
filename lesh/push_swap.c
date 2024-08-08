#include "push_swap.h"

void	algo(t_stack *a, t_stack *b)
{
	pa(a, b);
	pa(a, b);

}

void	lets_continue(t_stack *a, t_stack *b)
{
	if (stack_len(a) == 4)
		sort_four(a);
	else if (stack_len == 5)
		sort_five(a);
	else
		algo(a, b);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (-1);
	ft_check_args(ac, av);
	//a = create_stack_from_args(ac, av);
	//if (stack_is_sorted(a))
	//	return (0);
	//if (stack_len(a) == 3)
	//{
	//	sort_three(a)
	//	return (0);
	//}
	//else
	//	lets_continue(a, b);
	free_stack(a);
	free_stack(b);
}
