/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 20:03:51 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/13 15:58:05 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node	*set_target_nodes_a(t_stack_node *stack_a,
	t_stack_node *stack_b)
{
	t_stack_node	*sa;
	t_stack_node	*sb;
	t_stack_node	*closest;

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
			sa->target_node = find_biggest(stack_b);
		sa = sa->next;
	}
	return (stack_a);
}

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

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
	ps(a, b, 'b');
}

void	init_node_a(t_stack_node **a, t_stack_node **b)
{
	current_index(*a);
	current_index(*b);
	*a = set_target_nodes_a(*a, *b);
	*a = cost_analyst(*a, *b);
	*a = set_cheapest(*a);
}
