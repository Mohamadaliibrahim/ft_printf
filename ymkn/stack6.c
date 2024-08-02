/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:05:47 by mohamibr          #+#    #+#             */
/*   Updated: 2024/08/02 20:05:51 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_contains(int num, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_validate_args(char **av, int flag, int i)
{
	long	tmp;

	while (av[i])
	{
		if (!ft_isnum(av[i]))
		{
			if (flag == 1)
				free_split(av);
			ft_error("Error");
		}
		tmp = ft_atoi(av[i]);
		if (tmp < -2147483648 || tmp > 2147483647)
		{
			if (flag == 1)
				free_split(av);
			ft_error("Error");
		}
		if (ft_contains(tmp, av, i))
		{
			if (flag == 1)
				free_split(av);
			ft_error("Error1");
		}
		i++;
	}
}

void	ft_check_args(int ac, char **av)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		flag = 1;
		i = 0;
	}
	else
		i = 1;
	ft_validate_args(av, flag, i);
	if (ac == 2)
		free_split(av);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
