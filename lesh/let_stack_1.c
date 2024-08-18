#include "push_swap.h"

int	find_min_value(t_stack *a)
{
	int		min;
	t_stack	*current;

	if (!a)
		return (INT_MAX);

	current = a;
	min = current->data;
	while (current)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	return (min);
}


t_stack *create_node(int value)
{
    t_stack *new_node;

    new_node = (t_stack *)malloc(sizeof(t_stack)); // Allocate memory for a new node
    if (!new_node)
        return (NULL); // Return NULL if memory allocation fails
    
    new_node->data = value;          // Set the data field to the provided value
    new_node->index = 0;             // Initialize index to 0 or set as needed later
    new_node->cost = 0;              // Initialize cost to 0 or set as needed later
    new_node->cheapest = 0;          // Initialize cheapest to 0 or false
    new_node->above_median = false;  // Initialize above_median to false
    new_node->target_node = NULL;    // Initialize target_node to NULL
    new_node->next = NULL;           // Initialize next pointer to NULL
    new_node->prev = NULL;           // Initialize prev pointer to NULL

    return (new_node); // Return the newly created node
}


t_stack	*create_stack_from_args(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*new_node;
	int		i;
	long	value;
	char	**split_args = NULL;

	if (ac == 2)
	{
		split_args = ft_split(av[1], ' ');
		if (!split_args)
			return (NULL);
		av = split_args;
		ac = 0;
		while (av[ac])
			ac++;
	}
	else
	{
		av++;
		ac--;
	}

	stack = NULL;
	i = ac - 1;
	while (i >= 0)
	{
		value = ft_atoi(av[i]);
		if (value > INT_MAX || value < INT_MIN)
		{
			ft_error("Integer out of bounds");
			free_stack(stack);
			if (split_args)
				free_it(split_args);
			return (NULL);
		}

		new_node = create_node(value);
		if (!new_node)
		{
			ft_error("Memory allocation failed");
			free_stack(stack);
			if (split_args)
				free_it(split_args);
			return (NULL);
		}

		new_node->next = stack;
		if (stack)
			stack->prev = new_node;
		stack = new_node;
		i--;
	}

	if (split_args)
		free_it(split_args);

	return (stack);
}


