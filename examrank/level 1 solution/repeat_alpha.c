#include <unistd.h>
#include <stdio.h>

void lower(char c)
{
    int i;
    int z = 0;
    i = c - 'a';
    while (z <= i)
    {
        write(1, &c, 1);
        z++;
    }
}

void upper(char c)
{
    int i;
    int z = 0;
    i = c - 'A';
    while (z <= i)
    {
        write(1, &c, 1);
        z++;
    }
}

void check(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            lower(str[i]);
        else if (str[i] >= 'A' && str[i] <= 'Z')
            upper(str[i]);
        else
            write(1, &str[i], 1);
        i++;
    }
}

int main(int ac,char *av[])
{
    if (ac < 2)
        return 0;
    else
        check(av[1]);
    write(1, "\n", 1);
    return 0;
}