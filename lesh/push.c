#include "push_swap.h"

static void push(t_stack **src, t_stack **dst)
{
    t_stack *tmp;

    if (*src == NULL)
        return;

    tmp = *src;
    *src = (*src)->next;

    if (*src != NULL)
        (*src)->prev = NULL;

    tmp->next = *dst;

    if (*dst != NULL)
        (*dst)->prev = tmp;

    *dst = tmp;
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
