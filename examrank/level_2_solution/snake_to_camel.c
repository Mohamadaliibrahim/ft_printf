#include <stdlib.h>
#include <unistd.h>

void    check(char *str)
{
    int i = 0;
    int f = 0;
    while (str[i])
    {
        if (str[i] == '_')
        {
            i++;
            str[i] -= 32;
        }
        write(1, &str[i], 1);
        i++;
    }
}

int main(int ac,char *av[])
{
    if (ac == 2)
        check(av[1]);
    write(1, "\n", 1);
    return 0;
}