#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	ft_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(0);
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
	free_stack(a);
	free_stack(b);
}
