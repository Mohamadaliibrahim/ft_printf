#include "push_swap.h"

static void	swap(t_stack **stack)
{
	int	z;
	int	y;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	z = (*stack)->data;
	y = (*stack)->next->data;
	(*stack)->data = y;
	(*stack)->next->data = z;
}

void	sa(t_stack **a)
{
	swap(a);
	printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
	printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	printf("ss\n");
}
//stop!