/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:18:04 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/12 19:46:43 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack_node	*rrs(t_stack_node *stack, char c)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (!stack || !stack->next)
		return (stack);
	last = stack;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = stack;
	stack->prev = last;
	if (c != ' ')
		ft_printf("rr%c\n", c);
	return (last);
}

void	rrr(t_stack_node **sa, t_stack_node **sb)
{
	if (*sa)
		*sa = rrs(*sa, ' ');
	if (*sb)
		*sb = rrs(*sb, ' ');
	ft_printf("rrr\n");
}
