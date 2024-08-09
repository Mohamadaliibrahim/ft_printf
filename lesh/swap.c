#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_node	*first;
	t_node	*second;
	int		temp_value;

	if (stack == NULL || *stack == NULL || (*stack)->top == NULL || (*stack)->top->next == NULL)
		return ;

	first = (*stack)->top;
	second = first->next;

	temp_value = first->value;
	first->value = second->value;
	second->value = temp_value;
}

void	sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}

//stop!