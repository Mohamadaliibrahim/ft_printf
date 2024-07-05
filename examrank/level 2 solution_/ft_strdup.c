#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

char *ft_strdup(char *str)
{
    int  i = 0;
    char *c;

    c = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
    if (!c)
        return NULL;
    while (str[i])
    {
        c[i] = str[i];
        i++;
    }
    c[i] = '\0';
    return c;
}