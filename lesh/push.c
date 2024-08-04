#include "push_swap.h"

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