#include <unistd.h>
#include <stdlib.h>

int check_for(char *str)
{
    int i = 0;
    int z = 0;
    while (str[i] != '\0')
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            z++;
        i++;
    }
    return z;
}

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void check(char *str)
{
    int i = 0;
    int j = 0;
    char *h;
    h = malloc(sizeof(char) * (ft_strlen(str) + check_for(str) + 1));
    if (!h)
        return ;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            h[j] = '_';
            j++;
        }
        h[j] = str[i];
        j++;
        i++;
    }
    h[j] = '\0';
    i = 0;
    while(h[i] != '\0')
    {
        if (h[i] >= 'A' && h[i] <= 'Z')
            h[i] += 32;
        write(1, &h[i], 1);
        i++;
    }
    free(h);
}

int main(int    ac,char *av[])
{
    if (ac == 2)
        check(av[1]);
    write(1, "\n", 1);
    return 0;
}