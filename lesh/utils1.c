/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:22:54 by mohamibr          #+#    #+#             */
/*   Updated: 2024/08/19 10:22:58 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = value;
	new_node->index = 0;
	new_node->cost = 0;
	new_node->cheapest = 0;
	new_node->above_median = false;
	new_node->target_node = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack	*create_stack_from_args(int ac, char **av)
{
	t_stack	*stack;
	char	**split_args;

	split_args = NULL;
	av = prepare_arguments(ac, av, &ac, &split_args);
	if (!av || build_stack(ac, av, &stack) == -1)
		return (NULL);
	if (split_args)
		free_it(split_args);
	return (stack);
}

char	**prepare_arguments(int ac, char **av, int *new_ac, char ***split_args)
{
	*split_args = NULL;
	if (ac == 2)
	{
		*split_args = ft_split(av[1], ' ');
		if (!*split_args)
			return (NULL);
		av = *split_args;
		*new_ac = 0;
		while (av[*new_ac])
			(*new_ac)++;
	}
	else
	{
		av++;
		*new_ac = ac - 1;
	}
	return (av);
}

int	build_stack(int ac, char **av, t_stack **stack)
{
	int	i;

	*stack = NULL;
	i = ac - 1;
	while (i >= 0)
	{
		if (add_node_to_stack(av[i], stack) == -1)
			return (-1);
		i--;
	}
	return (0);
}
//stop!