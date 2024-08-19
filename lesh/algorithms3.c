/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:20:54 by mohamibr          #+#    #+#             */
/*   Updated: 2024/08/19 10:21:10 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max_node(t_stack *stack)
{
	t_stack	*max_node;

	max_node = stack;
	while (stack)
	{
		if (stack->data > max_node->data)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

t_stack	*set_target_nodes_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*sa;
	t_stack	*sb;
	t_stack	*closest;

	sa = stack_a;
	while (sa)
	{
		sb = stack_b;
		closest = NULL;
		while (sb)
		{
			if (sa->data > sb->data && (!closest || sb->data > closest->data))
				closest = sb;
			sb = sb->next;
		}
		if (closest)
			sa->target_node = closest;
		else
			sa->target_node = find_max_node(stack_b);
		sa = sa->next;
	}
	return (stack_a);
}
