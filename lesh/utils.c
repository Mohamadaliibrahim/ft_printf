/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:22:40 by mohamibr          #+#    #+#             */
/*   Updated: 2024/08/19 10:22:44 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *a)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = a;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

int	stack_is_sorted(t_stack *a)
{
	t_stack	*current;
	int		z;

	if (a == NULL)
		return (1);
	current = a;
	z = current->data;
	current = current->next;
	while (current)
	{
		if (z > current->data)
			return (0);
		z = current->data;
		current = current->next;
	}
	return (1);
}

void	sort_three_1(t_stack **a)
{
	t_stack	*x;
	t_stack	*y;
	t_stack	*z;

	x = *a;
	y = x->next;
	z = y->next;
	if (x->data > y->data && y->data < z->data && x->data > z->data)
	{
		ra(a);
	}
	else if (x->data < y->data && y->data > z->data && x->data < z->data)
	{
		sa(a);
		ra(a);
	}
	else if (x->data < y->data && y->data > z->data && x->data > z->data)
	{
		rra(a);
	}
}

void	sort_three(t_stack **a)
{
	t_stack	*x;
	t_stack	*y;
	t_stack	*z;

	if (!a || !*a || stack_is_sorted(*a))
		return ;
	x = *a;
	y = x->next;
	z = y->next;
	if (x->data > y->data && y->data < z->data && x->data < z->data)
	{
		sa(a);
	}
	else if (x->data > y->data && y->data > z->data && x->data > z->data)
	{
		sa(a);
		rra(a);
	}
	else
		sort_three_1(a);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	if (stack == NULL)
		return ;
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
//stop!!