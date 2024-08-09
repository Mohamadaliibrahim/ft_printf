#include "push_swap.h"

static void push(t_stack **src, t_stack **dst)
{
    t_node *tmp;

    if ((*src) == NULL || (*src)->top == NULL)
        return ;

    tmp = (*src)->top->next;

    if (*dst == NULL) // Initialize dst stack if it's NULL
    {
        *dst = (t_stack *)malloc(sizeof(t_stack));
        if (*dst == NULL)
            return ; // Handle malloc failure
        (*dst)->top = NULL;
        (*dst)->size = 0;
    }

    (*src)->top->next = (*dst)->top;
    if ((*dst)->top != NULL)
        (*dst)->top->prev = (*src)->top;

    (*dst)->top = (*src)->top;
    (*src)->top = tmp;

    if ((*src)->top != NULL)
        (*src)->top->prev = NULL;

    (*dst)->size++;
    (*src)->size--;
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