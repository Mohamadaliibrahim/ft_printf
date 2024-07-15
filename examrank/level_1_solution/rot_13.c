#include <unistd.h>

void    lower(char c)
{
    if (c >= 'a' && c <= 'm')
        c += 13;
    else if (c >= 'n' && c <= 'z')
        c -= 13;
    write(1, &c, 1);
}

void    upper(char c)
{
    if (c >= 'A' && c <= 'M')
        c += 13;
    else if (c >= 'N' && c <= 'Z')
        c -= 13;
    write(1, &c, 1);
}

void    check(char *str)
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

int main(int ac, char *av[])
{
    if (ac < 2)
    {
        write(1, "\n", 1);
        return 0;
    }
    else
        check(av[1]);
    write (1, "\n", 1);
    return 0;
}