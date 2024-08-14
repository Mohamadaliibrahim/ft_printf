/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 00:34:17 by ajabado           #+#    #+#             */
/*   Updated: 2024/07/01 17:50:03 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_clear_argv(char **argv)
{
	char	*arg;

	if (!argv)
		return ;
	while (*argv)
	{
		arg = *argv;
		argv++;
		free(arg);
	}
	*argv = NULL;
}

static int	ft_atoi_strict(int i, char **argv, t_stack **a, int argc)
{
	int				sign;
	long long int	res;
	int				j;

	res = 0;
	j = 0;
	sign = 1;
	if (argv[i][0] == '-' && argv[i][j++])
		sign = -1;
	while (ft_isdigit(argv[i][j]))
		res = res * 10 + ((argv[i][j++]) - 48);
	if ((sign * res) > 2147483647 || (sign * res) < -2147483648
		|| ft_strlen(argv[i]) != (size_t) ft_nbrlen(sign * res))
	{
		if (argc == 2)
		{
			ft_clear_argv(argv);
			free(argv);
		}
		ft_stack_clear(a);
		ft_error();
	}
	return (sign * res);
}

static int	ft_check_argv(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isspace(argv[i][j]))
				while (ft_isspace(argv[i][j]))
					j++;
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static t_stack	*ft_parse_one_arg(char **argv, int argc)
{
	t_stack	*a;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	argv = ft_split(argv[1], 32);
	if (!ft_check_argv(argv))
	{
		ft_clear_argv(argv);
		free(argv);
		ft_error();
	}
	while (argv[i])
	{
		j = ft_atoi_strict(i, argv, &a, argc);
		ft_stack_add_back(&a, ft_stack_new(j));
		i++;
	}
	ft_clear_argv(argv);
	free(argv);
	return (a);
}

t_stack	*ft_parse(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc < 2)
		exit(0);
	if (argc == 2)
		a = ft_parse_one_arg(argv, argc);
	else
	{
		if (!ft_check_argv(argv + 1))
			ft_error();
		while (i < argc)
		{
			j = ft_atoi_strict(i, argv, &a, argc);
			ft_stack_add_back(&a, ft_stack_new(j));
			i++;
		}
	}
	return (a);
}
