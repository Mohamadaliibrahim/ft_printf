#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

void	check(char *str,char *c, char *z)
{
	int i = 0;
	int x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c[0])
		{
			str[i] = z[0];
			x++;
		}
		write(1,&str[i], 1);
		i++;
	}
	if (x == 0)
		write(1, str, ft_strlen(str));
}

int main(int ac, char *av[])
{
    if (ac == 4)
    {
		check(av[1],av[2],av[3]);
    }
    write(1, "\n", 1);
    return 0;
}