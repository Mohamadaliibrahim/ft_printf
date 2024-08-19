/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:24:54 by mohamibr          #+#    #+#             */
/*   Updated: 2024/08/19 10:24:58 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (-1);
	ft_check_args(ac, av);
	a = create_stack_from_args(ac, av);
	b = NULL;
	if (a == NULL)
	{
		ft_error("Error");
		return (1);
	}
	if (stack_is_sorted(a))
		finish_program(a, b);
	if (stack_len(a) == 2)
		sa(&a);
	if (stack_len(a) == 3)
		sort_three(&a);
	else
		push_swap(&a, &b, stack_len(a));
	free_stack(a);
	free_stack(b);
	return (0);
}
