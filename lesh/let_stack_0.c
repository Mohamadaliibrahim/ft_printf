#include "push_swap.h"

int	stack_len(t_stack *a)
{
	t_stack	*current;  // Changed t_node to t_stack
	int		i;

	i = 0;
	current = a;  // No 'top', start directly from 'a'
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

int	stack_is_sorted(t_stack *a)
{
	t_stack	*current;  // Changed t_node to t_stack
	int		z;

	if (a == NULL)
		return (1);
	current = a;  // No 'top', start directly from 'a'
	z = current->data;  // Use 'data' instead of 'value'
	current = current->next;
	while (current)
	{
		if (z > current->data)  // Use 'data' instead of 'value'
			return (0);
		//printf("current: %d prev: %d\n",current->data, z);
		z = current->data;  // Use 'data' instead of 'value'
		current = current->next;
	}
	return (1);
}

void	sort_three_1(t_stack **a)
{
	t_stack	*x;  // Changed t_node to t_stack
	t_stack	*y;
	t_stack	*z;

	x = *a;  // No 'top', start directly from '*a'
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
	t_stack	*x;  // Changed t_node to t_stack
	t_stack	*y;
	t_stack	*z;

	if (!a || !*a || stack_is_sorted(*a))
		return;
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
	t_stack	*temp;  // Changed t_node to t_stack

	if (stack == NULL)
		return;
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
