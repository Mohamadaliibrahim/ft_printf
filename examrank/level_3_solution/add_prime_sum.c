#include <unistd.h>

int ft_atoi(char *str)
{
    int i = 0;
    int r = 0;
    int s = 1;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '-')
    {
        i++;
        s = -1;
    }
    else if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        r = r * 10 + str[i] - '0';
        i++;
    }
    return (r * s);
}

void    ft_putnbr(int c)
{
    char *hey = "0123456789";
    if (c > 9)
        ft_putnbr(c/10);
    write(1, &hey[c % 10], 1);
}
void	check1(int c)
{
	int i = 2;
	int s = 0;
	int f = 0;
	while (i <= c)
	{
		int  j = 2;
		f = 0;
		while (j < i)
		{
			if (i % j == 0)
			{
				f = 1;
				break;
			}
			j++;
		}
		if (f == 0)
		{
			s += i;
		}
		i++;
	}
	ft_putnbr(s);
}
void	check(char *str)
{
	int c = ft_atoi(str);
	if (c < 0)
	{
		write(1, "0", 1);
		write(1, "\n", 1);
		return ;
	}
	if (c < 2)
		return ;
	check1(c);
}

int main(int ac,char *av[])
{
    if (ac < 2)
	{
		write(1, "0", 1);
		write(1, "\n", 1);
		return ;
	}
    check(av[1]);
    write(1, "\n", 1);
    return (0);
}