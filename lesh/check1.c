/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:21:45 by mohamibr          #+#    #+#             */
/*   Updated: 2024/08/19 10:21:52 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_it(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	ft_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(0);
}

void	ft_validate_args(char **av, int flag, int i)
{
	long	tmp;

	while (av[i])
	{
		if (!ft_isnum(av[i]))
		{
			if (flag)
				free_it(av);
			ft_error("Error\n");
		}
		tmp = ft_atoi(av[i], av, flag);
		if (tmp < -2147483648 || tmp > 2147483647)
		{
			if (flag == 1)
				free_it(av);
			ft_error("Error\n");
		}
		if (ft_contains(tmp, av, i, flag))
		{
			if (flag == 1)
				free_it(av);
			ft_error("Error\n");
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
		free_it(av);
}
//stop!
