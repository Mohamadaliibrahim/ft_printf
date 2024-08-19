/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:22:00 by mohamibr          #+#    #+#             */
/*   Updated: 2024/08/19 10:22:03 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_contains(int num, char **av, int i, int flag)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i], av, flag) == num)
			return (1);
		i++;
	}
	return (0);
}

long	ft_atoi(char *nptr, char **av, int flag)
{
	size_t		i;
	int			neg;

	i = 0;
	neg = 0;
	check_sign_and_whitespace(nptr, &i, &neg, flag, av);
	return (convert_to_long(nptr, i, neg));
}

void	check_sign_and_whitespace(char *nptr, size_t *i, int *neg, int flag, char **av)
{
	if ((nptr[*i] == '-' || nptr[*i] == '+') && ft_strlen(nptr) == 1 && av)
	{
		ft_printf("Error\n");
		if (flag)
			free_it(av);
		exit (1);
	}
	while (nptr[*i] == ' ' || (nptr[*i] >= 9 && nptr[*i] <= 13))
		(*i)++;
	if (nptr[*i] == '+' || nptr[*i] == '-')
	{
		if (nptr[*i] == '-')
			*neg = 1;
		(*i)++;
	}
}

long	convert_to_long(char *nptr, size_t i, int neg)
{
	long	ans;

	ans = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (neg == 1)
			ans = (ans * 10) - (nptr[i] - '0');
		else
			ans = (ans * 10) + (nptr[i] - '0');
		i++;
	}
	return (ans);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}
