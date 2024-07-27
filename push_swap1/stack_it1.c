#include "push_swap.h"

void	sa(t_stack *a, int c)
{
	int	z;
	int	y;

	if (a && a->next)
	{
		z = a->data;
		y = a->next->data;
		a->data = y;
		a->next->data = z;
	}
	if (c)
		ft_printf("sa\n");
}

void	sb(t_stack *a, int c)
{
	int	z;
	int	y;

	if (a && a->next)
	{
		z = a->data;
		y = a->next->data;
		a->data = y;
		a->next->data = z;
	}
	if (c)
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b, int c)
{
	sa(a, c);
	sb(b, c);
}

void	ra(t_stack *a, int c)
{
	t_stack	*temp;
	int		first_data;

	if (!a || !a->next)
		return ;
	first_data = a->data;
	temp = a;
	while (temp->next)
	{
		temp->data = temp->next->data;
		temp = temp->next;
	}
	a->data = first_data;
	if (c)
		ft_printf("ra\n");
}

void	rb(t_stack *a, int c)
{
	t_stack	*temp;
	int		first_data;

	if (!a || !a->next)
		return ;
	first_data = a->data;
	temp = a;
	while (temp->next)
	{
		temp->data = temp->next->data;
		temp = temp->next;
	}
	a->data = first_data;
	if (c)
		ft_printf("rb\n");
}
// stop!!
