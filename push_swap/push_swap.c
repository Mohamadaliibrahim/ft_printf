#include "push_swap.h"

bool	has_duplicates(char **array)
{
	int	i;
	int	j;

	while (array[i])
	{
		j = i + 1;
		while (array[j])
		{
			if (ft_strcmp(array[i], array[j]) == 0)
				return (true);
			j++;
		}
		i++;
	}
	i = 0;
	while (array[i])
	{
		if (is_valid_number(array[i]) == false)
			return (false);
		i++;
	}
	return (false);
}

int	check_for_error(char *str[])
{
	int	i;
	int	j;
	int	c;
	int	d;

	i = 0;
	while (str[i])
	{
		c = ft_atoi(str[i]);
		j = 0;
		while (j < i)
		{
			d = ft_atoi(str[j]);
			if (d == c)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

char	**check_alpha(char *av[])
{
	if (alpha(av[1]))
	{
		ft_printf("Error\n");
		exit (1);
	}
	av = ft_split(av[1], ' ');
	if (!check_for_error(av))
	{
		free_split(av);
		ft_printf("Error\n");
		free (av);
		exit (1);
	}
	return (av);
}

int	main(int ac, char *av[])
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
		av = check_alpha(av);
	if (has_duplicates(av) == false)
	{
		init_stack_a(&a, av + 1);
		if (!stack_sorted(a))
		{
			if (stack_len(a) == 2)
				sa(&a, false);
			else if (stack_len(a) == 3)
				sort_three(&a);
			else
				sort_stacks(&a, &b);
		}
	}
	if ()
	free_split(av);
	free_stack(&b);
	free_stack(&a);
	return (0);
}
