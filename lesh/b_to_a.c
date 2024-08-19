/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:20:09 by mohamibr          #+#    #+#             */
/*   Updated: 2024/08/19 10:20:17 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*set_target_nodes_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*sa;
	t_stack	*sb;
	t_stack	*closest;

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

void	move_b_to_a(t_stack **a, t_stack **b)
{
	bring_on_top(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	init_node_b(t_stack **a, t_stack **b)
{
	current_index(*a);
	current_index(*b);
	*b = set_target_nodes_b(*a, *b);
}

void	bring_on_top(t_stack **stack, t_stack *desired_node, char stack_name)
{
	while (*stack != desired_node)
	{
		if (desired_node->above_median)
		{
			if (stack_name == 'a')
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if (stack_name == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}

//stop!
