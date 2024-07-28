#include "push_swap.h"

void	rra(t_stack *a, bool c)
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
	if (!c)
		ft_printf("rra\n");
}

void	rrb(t_stack *a, bool c)
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
	if (!c)
		ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b, bool c)
{
	rra(a, c);
	rrb(b, c);
}

static void	rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapset = true;
}
//stop !!