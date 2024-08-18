/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 20:03:51 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/13 15:55:43 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node	*set_target_nodes_b(t_stack_node *stack_a,
t_stack_node *stack_b)
{
	t_stack_node	*sa;
	t_stack_node	*sb;
	t_stack_node	*closest;

	sb = stack_b;
	while (sb)
	{
		sa = stack_a;
		closest = NULL;
		while (sa)
		{
			if ((sa->data > sb->data) && (!closest || sa->data < closest->data))
				closest = sa;
			sa = sa->next;
		}
		if (closest)
			sb->target_node = closest;
		else
			sb->target_node = find_smallest(stack_a);
		sb = sb->next;
	}
	return (stack_b);
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	bring_on_top(a, (*b)->target_node, 'a');
	ps(b, a, 'a');
}

void	init_node_b(t_stack_node **a, t_stack_node **b)
{
	current_index(*a);
	current_index(*b);
	*b = set_target_nodes_b(*a, *b);
}
