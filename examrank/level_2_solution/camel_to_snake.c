#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

void    check(char *str)
{
    int i = 0;
    int z = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            z++;
        i++;
    }
    if (z == 0)
        return ;
    i = 0;
    char *c = malloc(sizeof(char) * (ft_strlen(str) + z + 1));
    if (!c)
        return ;
    int j = 0;
    while (str[i])
    {
        while (str[i + 1] >= 'A' && str[i] <= 'Z')
        {
            c[j] = '_';
            j++;
            c[j] = str[i] + 32;
            i++;
            j++;
        }
        c[j] = str[i];
        j++;
        i++;
    }
    write(1,c,ft_strlen(c));
}

int main (int ac, char *av[])
{
    if (ac == 2)
        check(av[1]);
    write(1, "\n", 1);
    return 0;
}