#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void	ft_putstr(char *str)
{
	write(1,str,ft_strlen(str));
}

void    check(char *str)
{
    int i = 0;
    int j = ft_strlen(str) - 1;
    char c;
    while (i < j)
    {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
        j--;
    }
    i = ft_strlen(str);
    ft_putstr(str);
}

int main(int ac, char *av[])
{
    if (ac < 2)
        return 0;
    else
        check(av[1]);
    write (1, "\n", 1);
    return 0;
}