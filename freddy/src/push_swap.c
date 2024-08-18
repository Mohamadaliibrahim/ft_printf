/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 08:56:29 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/14 19:41:50 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node	*tinysort(t_stack_node *sa)
{
	t_stack_node	*biggest;

	biggest = find_biggest(sa);
	if (sa->data == biggest->data)
		sa = rs(sa, 'a');
	else if (sa->next->data == biggest->data)
		sa = rrs(sa, 'a');
	if (sa->data > sa->next->data)
		sa = sw(sa, 'a');
	return (sa);
}

void	bring_on_top(t_stack_node **stack,
t_stack_node *desired_node, char stack_name)
{
	while (*stack != desired_node)
	{
		if (desired_node->above_median)
			*stack = rs(*stack, stack_name);
		else
			*stack = rrs(*stack, stack_name);
	}
}

t_stack_node	*push_swap(t_stack_node *sa, t_stack_node *sb, int size_a)
{
	if (size_a-- > 3 && !sorted(sa))
		ps(&sa, &sb, 'b');
	if (size_a-- > 3 && !sorted(sa))
		ps(&sa, &sb, 'b');
	while (size_a-- > 3 && !sorted(sa))
	{
		init_node_a(&sa, &sb);
		move_a_to_b(&sa, &sb);
	}
	sa = tinysort(sa);
	while (sb)
	{
		init_node_b(&sa, &sb);
		move_b_to_a(&sa, &sb);
	}
	current_index(sa);
	while (sa->data != find_smallest(sa)->data)
	{
		if (find_smallest(sa)->above_median)
			sa = rs(sa, 'a');
		else
			sa = rrs(sa, 'a');
	}
	return (sa);
}
