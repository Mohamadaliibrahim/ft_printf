#include "push_swap.h"

#include "push_swap.h"

int	stack_len(t_stack *a)
{
	t_node	*current;
	int		i;

	i = 0;
	current = a->top;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

int	stack_is_sorted(t_stack *a)
{
	t_node	*current;
	int		z;

	if (a == NULL || a->top == NULL)
		return (1);
	current = a->top;
	z = current->value;
	current = current->next;
	while (current)
	{
		if (z > current->value)
			return (0);
		z = current->value;
		current = current->next;
	}
	return (1);
}

void	sort_three_1(t_stack **a)
{
	t_node	*x;
	t_node	*y;
	t_node	*z;

	x = (*a)->top;
	y = x->next;
	z = y->next;
	if (x->value > y->value && y->value < z->value && x->value > z->value)
	{
		ra(a);
	}
	else if (x->value < y->value && y->value > z->value && x->value < z->value)
	{
		sa(a);
		ra(a);
	}
	else if (x->value < y->value && y->value > z->value && x->value > z->value)
	{
		rra(a);
	}
}

void	sort_three(t_stack **a)
{
	t_node	*x;
	t_node	*y;
	t_node	*z;

	if (!a || !*a || !(*a)->top || !(*a)->top->next || stack_is_sorted(*a))
		return ;
	x = (*a)->top;
	y = x->next;
	z = y->next;
	if (x->value > y->value && y->value < z->value && x->value < z->value)
	{
		sa(a);
	}
	else if (x->value > y->value && y->value > z->value && x->value > z->value)
	{
		sa(a);
		rra(a);
	}
	else
		sort_three_1(a);
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	temp = stack->top;
	while (stack->top)
	{
		temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
	}
	free(stack);
}

//stop!