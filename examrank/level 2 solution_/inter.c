#include <unistd.h>

int is_there(char *str,char c, int end)
{
    int i = 0;
    while (i < end)
    {
        if (str[i] == c)
            return 0;
        i++;
    }
    return 1;
}

void    check(char *str1, char *str2)
{
    int i = 0;
    int j = 0;
    while (str1[i])
    {
        if (is_there(str2, str1[i], j) && is_there(str1, str1[i], i))
            write(1, &str1[i], 1);
        i++;
    }
}

int main(int ac, char *av[])
{
    if (ac == 3)
        check(av[1], av[2]);
    write(1, "\n", 1);
    return (0);
}