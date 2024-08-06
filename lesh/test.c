#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void	lets_push(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*z;
	int		i;

	z = *a;
	ft_printf("lets(a):\n");
	while (z)
	{
		ft_printf("%d\n", z->data);
		z = z->next;
	}
	i = stack_len(*a);
	while (i > 0)
	{
		pb(a, b);
		i--;
	}
	temp = *b;
	ft_printf("lets(b):\n");
	while (temp)
	{
		ft_printf("%d\n", temp->data);
		temp = temp->next;
	}
	free_stack(z);
	free_stack(temp);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	if (!ac)
		return (0);
	a = NULL;
	b = NULL;
	a = create_stack_from_args(ac, av);
	lets_push(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
