#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = 0;
	stack->cost = 0;
	stack->target_node = NULL;  // Correct member assignment
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}


int	stack_is_empty(t_stack *stack)
{
	return (stack == NULL);
}

void	finish_program(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	exit(0);
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*min;
	t_stack	*temp;

	min = stack;
	temp = stack;
	while (stack != NULL)
	{
		if (min->data > stack->data)
			min = stack;
		stack = stack->next;
	}
	stack = temp;
	return (min);
}

void current_index(t_stack *stack)
{
    int i;
    int median;

    if (!stack)
        return;
    i = 0;
    median = stack_len(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if (i <= median)
            stack->above_median = true;
        else
            stack->above_median = false;
        stack = stack->next;
        i++;
    }
}
