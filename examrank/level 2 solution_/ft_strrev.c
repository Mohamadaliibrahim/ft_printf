#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

char *ft_strrev(char *str)
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
    str[ft_strlen(str)] = '\0';
    return str;
}

int main (int ac, char *av[])
{
    char *str;
    if (ac == 2)
        str = ft_strrev(av[1]);
    write(1, str, ft_strlen(str));
    write(1, "\n", 1);
    return 0;
}