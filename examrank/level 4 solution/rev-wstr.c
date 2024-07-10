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
    int i = ft_strlen(str) - 1;
    int j = 0;
    char *c = malloc(sizeof(char) * (ft_strlen(str) + 1));
    if (!c)
        return ;
    while (i >= 0)
    {
        if(str[i] == ' ' || str[i] == '\t' || i == 0)
        {
            int x = i;
            if (i > 0)
                x++;
            while (str[x] != ' ' && str[i] != '\t' && str[x] != '\0')
            {
                c[j] = str[x];
                x++;
                j++;
            }
            if (i > 0)
            {
                c[j] = ' ';
                j++;
            }
            else if( i == 0)
                c[j] = '\0';
        }
        i--;
    }
    write(1, c, ft_strlen(c));
}

int main(int ac, char *av[])
{
    if (ac == 2)
        check(av[1]);
    write(1, "\n", 1);
    return (0);
}