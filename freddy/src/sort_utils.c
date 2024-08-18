/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:06:46 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/14 19:41:18 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_size(t_stack_node *sa)
{
	t_stack_node	*temp;
	int				size;

	size = 0;
	temp = sa;
	while (sa != NULL)
	{
		sa = sa->next;
		size++;
	}
	sa = temp;
	return (size);
}

t_stack_node	*find_smallest(t_stack_node *stack)
{
	t_stack_node	*min;
	t_stack_node	*temp;

	min = stack;
	temp = stack;
	while (stack != NULL)
	{
		if (min->data > stack->data)
			min = stack;
		stack = stack->next;
	}
	stack = temp;
	return (min);
}

t_stack_node	*find_biggest(t_stack_node *stack)
{
	t_stack_node	*max;
	t_stack_node	*temp;

	max = stack;
	temp = stack;
	while (stack != NULL)
	{
		if (max->data < stack->data)
			max = stack;
		stack = stack->next;
	}
	stack = temp;
	return (max);
}

int	sorted(t_stack_node *sa)
{
	while (sa != NULL && sa->next != NULL)
	{
		if (sa->data > sa->next->data)
			return (0);
		sa = sa->next;
	}
	return (1);
}

void	sort(t_stack_node *sa, t_stack_node *sb)
{
	int	size_a;

	size_a = stack_size(sa);
	if (size_a == 2)
	{
		if (sa->data > sa->next->data)
			sa = sw(sa, 'a');
	}
	else if (size_a == 3)
		sa = tinysort(sa);
	else
		sa = push_swap(sa, sb, size_a);
	free_stack(sa);
}
