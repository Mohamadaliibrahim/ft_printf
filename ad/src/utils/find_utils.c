/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 00:50:01 by ajabado           #+#    #+#             */
/*   Updated: 2024/07/01 00:50:01 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_find_index(t_stack *stack, int nbr)
{
	int		i;

	i = 0;
	while (stack->nbr != nbr)
	{
		i++;
		stack = stack->next;
	}
	stack->index = 0;
	return (i);
}

int	ft_find_place_b(t_stack *stack_b, int to_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (to_push > stack_b->nbr && to_push < ft_stack_last(stack_b)->nbr)
		i = 0;
	else if (to_push > ft_max(stack_b) || to_push < ft_min(stack_b))
		i = ft_find_index(stack_b, ft_max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->nbr < to_push || tmp->nbr > to_push)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	ft_find_place_a(t_stack *stack_a, int to_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (to_push < stack_a->nbr && to_push > ft_stack_last(stack_a)->nbr)
		i = 0;
	else if (to_push > ft_max(stack_a) || to_push < ft_min(stack_a))
		i = ft_find_index(stack_a, ft_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->nbr > to_push || tmp->nbr < to_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
