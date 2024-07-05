#include <unistd.h>
#include <stdlib.h>

void    ft_putnbr(int c)
{
    char str[] = "0123456789";
    if (c == -2147483648)
    {
        write(1, "-2147483648", 11);
        return ;
    }
    if (c < 0)
    {
        c = -c;
        write(1, "-", 1);
    }
    if (c > 9)
        ft_putnbr(c / 10);
    write(1, &str[c%10], 1);
}

void    check(char *str1,char *c,char *str2)
{
    int r = 0;
    int x = atoi(str1);
    int y = atoi(str2);
    if (c[1] != '\0')
        write(1, "error", 5);
    if (c[0] == '*')
        r = x * y;
    else if (c[0] == '+')
        r = x + y;
    else if (c[0] == '-')
        r = x - y;
    else if (c[0] == '/')
        {
            if ( y == 0)
            {
                write(1, "error", 5);
                return ;
            }
            r = x / y;
        }
    else if (c[0] == '%')
        {
            if ( y == 0)
            {
                write(1, "error", 5);
                return ;
            }
            r = x % y;
        }
    ft_putnbr(r);
}

int main (int ac, char *av[])
{
    if (ac == 4)
        check(av[1],av[2],av[3]);
    write(1, "\n", 1);
    return 0;
}