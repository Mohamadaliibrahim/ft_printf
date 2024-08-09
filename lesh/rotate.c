#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_node	*temp;
	t_node	*first;
	int		first_value;

	if (!stack || !*stack || !(*stack)->top || !(*stack)->top->next)
		return ;

	first = (*stack)->top;
	first_value = first->value;
	temp = (*stack)->top;

	while (temp->next)
	{
		temp->value = temp->next->value;
		temp = temp->next;
	}
	temp->value = first_value;
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