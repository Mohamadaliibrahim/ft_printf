#include "libft.h"

int count_digit(int c)
{
    int ch;

    ch = 0;
    if (c <= 0)
        ch = 1;
    while (c != 0)
    {
        c /= 10;
        ch++;
    }
    return ch;
}

char *ft_itoa(int n)
{
    int i;
    char *ch;
    long x;

    if (n == -2147483648)
        return (ft_strdup("-2147483648"));
    if (n == 0)
        return (ft_strdup("0"));
    i = count_digit(n);
    x = n;
    ch = (char *)malloc(sizeof(char) * (i + 1));
    if (!ch)
        return (NULL);
    ch[i] = '\0';
    if (x < 0)
    {
        ch[0] = '-';
        x = -x;
    }
    while (i > 0 && ch[i - 1] != '-')
    {
        ch[--i] = (x % 10) + '0';
        x /= 10;
    }
    return (ch);
}