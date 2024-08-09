#include <unistd.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	check(char *str)
{
	int	i;
	int	end;

	i = ft_strlen(str) - 1;
	while (i >= 0 && (str[i] == ' '))
		i--;
	end = i;
	while ((i >= 0 && (str[i] != ' ')))
		i--;
	i++;
	while (i <= end)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		main(int	ac, char	*av[])
{
	if (ac == 2)
		check(av[1]);
	write (1, "\n", 1);
	return (0);
}