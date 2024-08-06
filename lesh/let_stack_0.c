#include "push_swap.h"

int	stack_len(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	stack_is_sorted(t_stack *a)
{
	int	z;

	if (a == NULL)
		return (1);
	z = a->data;
	a = a->next;
	while (a)
	{
		if (z > a->data)
			return (0);
		z = a->data;
		a = a->next;
	}
	return (1);
}

void	sort_three_1(t_stack **a)
{
	t_stack	*x;
	t_stack	*y;
	t_stack	*z;

	x = *a;
	y = x->next;
	z = y->next;
	if (x->data > y->data && y->data < z->data && x->data > z->data)
	{
		ra(a);
	}
	else if (x->data < y->data && y->data > z->data && x->data < z->data)
	{
		sa(a);
		ra(a);
	}
	else if (x->data < y->data && y->data > z->data && x->data > z->data)
	{
		rra(a);
	}
}

void	sort_three(t_stack **a)
{
	t_stack	*x;
	t_stack	*y;
	t_stack	*z;

	if (!a || !*a || !(*a)->next || stack_is_sorted(*a))
		return ;
	x = *a;
	y = x->next;
	z = y->next;
	if (x->data > y->data && y->data < z->data && x->data < z->data)
	{
		sa(a);
	}
	else if (x->data > y->data && y->data > z->data && x->data > z->data)
	{
		sa(a);
		rra(a);
	}
	else
		sort_three_1(a);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	if (!stack)
		return ;
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
//stop!