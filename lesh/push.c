#include "push_swap.h"

int	pop(t_stack **stack)
{
	t_stack	*temp;
	int		data;

	if (!stack || !*stack)
		return (0);

	temp = *stack;
	data = temp->data;
	*stack = (*stack)->next;
	free(temp);
	return (data);
}


static	void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if ((*src) == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	(*dst) = (*src);
	*src = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
}
//stop!