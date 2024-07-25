/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:49:43 by mohamibr          #+#    #+#             */
/*   Updated: 2024/07/25 12:50:29 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//char	*init_stack_a(t_stack	**a, char	*av[])

int	stack_len(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	stack_stored(t_stack **a)
{
	int	z;

	if (a == NULL)
		return (1);
	z = a->data;
	a = a->next;
	while (a)
	{
		if (z > a->data)
			return (0);
		z = a->data;
		a = a->next;
	}
	return (1);
}

void	sort_three(t_stack **a)
{
	if (stack_stored(a))
		do_it(a);
	else
	{

	}
}
