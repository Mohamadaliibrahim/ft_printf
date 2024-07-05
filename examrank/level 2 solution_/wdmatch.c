#include <unistd.h>

void    check(char *str1, char *str2)
{
    int i = 0;
    int j = 0;
    while (str1[i])
    {
        while (str2[j] && str2[j] != str1[i])
            j++;
        if (str2[j] == '\0')
            return ;
        i++;
        j++;
    }
    write(1, str1, i);
}

int main(int ac, char *av[])
{
    if (ac == 3)
        check(av[1], av[2]);
    write(1, "\n", 1);
    return 0;
}