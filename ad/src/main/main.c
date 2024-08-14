/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 00:36:18 by ajabado           #+#    #+#             */
/*   Updated: 2024/07/01 00:36:18 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = ft_parse(argc, argv);
	if (!a || ft_check_dup(a))
	{
		ft_stack_clear(&a);
		ft_error();
	}
	if (!ft_is_sorted(a))
		ft_sort(&a);
	ft_stack_clear(&a);
	return (0);
}
