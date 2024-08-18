/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:20:31 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/12 19:47:36 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack_node	*rs(t_stack_node *stack, char c)
{
	t_stack_node	*last_head;
	t_stack_node	*new_head;
	t_stack_node	*temp;

	last_head = stack;
	new_head = stack->next;
	temp = new_head;
	new_head->prev = NULL;
	while (new_head->next != NULL)
		new_head = new_head->next;
	new_head->next = last_head;
	last_head->prev = new_head;
	last_head->next = NULL;
	if (c != ' ')
		ft_printf("r%c\n", c);
	return (temp);
}

void	rr(t_stack_node **sa, t_stack_node **sb)
{
	if (sa && *sa && (*sa)->next)
		*sa = rs(*sa, ' ');
	if (sb && *sb && (*sb)->next)
		*sb = rs(*sb, ' ');
	ft_printf("rr\n");
}
