/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 22:13:35 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/13 15:59:30 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = stack_size(stack) / 2;
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

t_stack_node	*set_cheapest(t_stack_node *stack)
{
	t_stack_node	*s;
	t_stack_node	*cost;

	s = stack;
	cost = stack;
	while (s)
	{
		if (cost->cost > s->cost)
			cost = s;
		s = s->next;
	}
	cost->cheapest = true;
	return (stack);
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	t_stack_node	*s;

	s = stack;
	while (s)
	{
		if (s->cheapest)
			return (s);
		s = s->next;
	}
	return (stack);
}

t_stack_node	*cost_analyst(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*s;
	int				size_a;
	int				size_b;

	s = stack_a;
	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	while (s)
	{
		s->cost = s->index;
		if (!(s->above_median))
			s->cost = size_a - (s->index);
		if (s->target_node->above_median)
			s->cost += s->target_node->index;
		else
			s->cost += size_b - (s->target_node->index);
		s = s->next;
	}
	return (stack_a);
}
