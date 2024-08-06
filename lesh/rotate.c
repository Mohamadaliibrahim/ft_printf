#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*first;
	int		first_data;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	first_data = first->data;
	temp = *stack;
	while (temp->next)
	{
		temp->data = temp->next->data;
		temp = temp->next;
	}
	temp->data = first_data;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
//stop!