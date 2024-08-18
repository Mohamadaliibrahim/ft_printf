/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:17:01 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/12 19:47:53 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack_node	*sw(t_stack_node *stack, char c)
{
	t_stack_node	*second;

	if (!stack || !stack->next)
		return (stack);
	second = stack->next;
	stack->next = second->next;
	if (second->next)
		second->next->prev = stack;
	second->next = stack;
	second->prev = stack->prev;
	stack->prev = second;
	if (c != ' ')
		ft_printf("s%c\n", c);
	return (second);
}

void	ss(t_stack_node **sa, t_stack_node **sb)
{
	if (sa && *sa && (*sa)->next)
		*sa = sw(*sa, ' ');
	if (sb && *sb && (*sb)->next)
		*sb = sw(*sb, ' ');
	ft_printf("ss\n");
}
