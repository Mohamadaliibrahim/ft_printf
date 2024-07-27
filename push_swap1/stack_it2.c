#include "push_swap.h"

void	rra(t_stack *a, int c)
{
	t_stack	*temp;
	t_stack	*last;
	int		last_data;

	if (!a || !a->next)
		return ;
	temp = a;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	last_data = temp->data;
	temp->next = NULL;

	temp = a;
	while (temp->next)
		temp = temp->next;
	temp->next = last;
	last->data = a->data;
	a->data = last_data;
	if (c)
		ft_printf("rra\n");
}

void	rrb(t_stack *a, int c)
{
	t_stack	*temp;
	t_stack	*last;
	int		last_data;

	if (!a || !a->next)
		return ;
	temp = a;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	last_data = temp->data;
	temp->next = NULL;

	temp = a;
	while (temp->next)
		temp = temp->next;
	temp->next = last;
	last->data = a->data;
	a->data = last_data;
	if (c)
		ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b, int c)
{
	rra(a, c);
	rrb(b, c);
}

void	rr(t_stack	*a, t_stack	*b, int	c)
{
	ra(a, c);
	rb(b, c);
}
// 1 more