/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:20:54 by mohamibr          #+#    #+#             */
/*   Updated: 2024/08/19 10:21:10 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
	{
		while (*b != cheapest_node->target_node && *a != cheapest_node)
			rr(a, b);
		current_index(*a);
		current_index(*b);
	}
	else if (!cheapest_node->above_median
		&& !cheapest_node->target_node->above_median)
	{
		while (*b != cheapest_node->target_node && *a != cheapest_node)
			rrr(a, b);
		current_index(*a);
		current_index(*b);
	}
	bring_on_top(a, cheapest_node, 'a');
	bring_on_top(b, cheapest_node->target_node, 'b');
	pb(a, b);
}

void	init_node_a(t_stack **a, t_stack **b)
{
	current_index(*a);
	current_index(*b);
	*a = set_target_nodes_a(*a, *b);
	*a = cost_analyst(*a, *b);
	*a = set_cheapest(*a);
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
