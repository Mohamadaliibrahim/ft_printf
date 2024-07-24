#include "push_swap.h"


int	check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= ' ' || (str[i] >= 9 && str[i] <= 13))
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac,char *av[])
{
	if (ac > 2)
	{
		if (check(av[1]))
		{
			int	i;

			i = 1;
			while (i < ac)
			{
				stack_it(av[i]);
			}
		}
	}
	else
	{
		char	*c;

		c = ft_split(av[1]);
		stack_it(c);
	}
	ft_printf(" ");
	return (0);
}