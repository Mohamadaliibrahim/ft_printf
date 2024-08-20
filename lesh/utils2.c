/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:23:04 by mohamibr          #+#    #+#             */
/*   Updated: 2024/08/19 10:23:08 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_node_to_stack(char *arg, t_stack **stack)
{
	long	value;
	t_stack	*new_node;

	value = ft_atoi(arg, NULL, 0);
	if (check_value_bounds(value, stack) == -1)
		return (-1);
	new_node = create_node(value);
	if (!new_node)
	{
		ft_error("Error");
		free_stack(*stack);
		return (-1);
	}
	link_new_node(new_node, stack);
	return (0);
}

int	check_value_bounds(long value, t_stack **stack)
{
	if (value > INT_MAX || value < INT_MIN)
	{
		ft_error("Error");
		free_stack(*stack);
		return (-1);
	}
	return (0);
}

void	link_new_node(t_stack *new_node, t_stack **stack)
{
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
//stop!
