#include "push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack)); // Use t_stack instead of t_node
	if (!new_node)
		return (NULL);
	new_node->data = value;  // Use 'data' instead of 'value'
	new_node->target = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
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


