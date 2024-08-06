#include "push_swap.h"


int	ft_contains(int num, char **av, int i)
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

long	ft_atoi(const char *nptr)
{
	size_t		i;
	long		ans;
	int			neg;

	i = 0;
	neg = 0;
	ans = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = 1;
		i++;
	}
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
				free_it(av);
			ft_error("Error");
		}
		tmp = ft_atoi(av[i]);
		if (tmp < -2147483648 || tmp > 2147483647)
		{
			if (flag == 1)
				free_it(av);
			ft_error("Error");
		}
		if (ft_contains(tmp, av, i))
		{
			if (flag == 1)
				free_it(av);
			ft_error("Error");
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
