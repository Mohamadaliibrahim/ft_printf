#include <level1.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	write(1,str,ft_strlen(str));
}

int main(int ac, char *av[])
{
	if (ac == 0)
		return 0;
	else
		ft_putstr(av[1]);
	write(1,"\n", 1);
	return 0;
}