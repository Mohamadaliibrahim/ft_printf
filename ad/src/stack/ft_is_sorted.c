/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:25:43 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/30 15:25:43 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	int	tmp;

	tmp = stack->nbr;
	while (stack)
	{
		if (tmp > stack->nbr)
			return (0);
		tmp = stack->nbr;
		stack = stack->next;
	}
	return (1);
}
