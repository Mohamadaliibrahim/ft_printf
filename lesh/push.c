#include "push_swap.h"

static	void	push(t_stack **src, t_stack **dst)
{
	t_node	*tmp;

	if ((*src) == NULL || (*src)->top == NULL)
		return ;

	tmp = (*src)->top->next;
	(*src)->top->next = (*dst)->top;
	(*dst)->top = (*src)->top;
	(*src)->top = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pb\n");
}

//stop!