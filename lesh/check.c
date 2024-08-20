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
	t_parse_info	info;

	info.i = 0;
	info.neg = 0;
	info.flag = flag;
	info.av = av;
	check_sign_and_whitespace(nptr, &info);
	return (convert_to_long(nptr, info.i, info.neg));
}

void	check_sign_and_whitespace(char *nptr, t_parse_info *info)
{
	if ((nptr[info->i] == '-' || nptr[info->i] == '+')
		&& ft_strlen(nptr) == 1 && info->av)
	{
		ft_printf("Error");
		if (info->flag)
			free_it(info->av);
		exit(1);
	}
	while (nptr[info->i] == ' ' || (nptr[info->i] >= 9 && nptr[info->i] <= 13))
		info->i++;
	if (nptr[info->i] == '+' || nptr[info->i] == '-')
	{
		if (nptr[info->i] == '-')
			info->neg = 1;
		info->i++;
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
