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
