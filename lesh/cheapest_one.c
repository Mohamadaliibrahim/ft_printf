/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:20:09 by mohamibr          #+#    #+#             */
/*   Updated: 2024/08/19 10:20:17 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*set_cheapest(t_stack *stack)
{
	t_stack	*s;
	t_stack	*c;

	s = stack;
	c = stack;
	while (s)
	{
		if (c->cost > s->cost)
			c = s;
		s = s->next;
	}
	c->cheapest = true;
	return (stack);
}

t_stack	*cost_analyst(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*s;
	int		size_a;
	int		size_b;

	s = stack_a;
	size_a = stack_len(stack_a);
	size_b = stack_len(stack_b);
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

t_stack	*get_cheapest(t_stack *stack)
{
	t_stack	*s;

	s = stack;
	while (s)
	{
		if (s->cheapest)
			return (s);
		s = s->next;
	}
	return (stack);
}
