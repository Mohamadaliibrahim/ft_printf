#include <unistd.h>

int	check(char *str, char c, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	unions(char *str1, char *str2)
{
	int i = 0;
	int j = 0;
	while (str1[i])
	{
		if (!check(str1, str1[i], i))
			write(1, &str1[i], 1);
		i++;
	}
	while (str2[j])
	{
		if (!check(str1, str2[j], -1) && !check(str2, str2[j], i))
			write(1, &str2[j], 1);
		j++;
	}

}
int	main(int	ac, char	*av[])
{
	if (ac == 3)
		unions(av[1], av[2]);
	write (1, "\n", 1);
	return (0);
}