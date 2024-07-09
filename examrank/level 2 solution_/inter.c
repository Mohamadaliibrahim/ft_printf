#include <unistd.h>

int was_there(char *str,char c,int end)
{
    int i = 0;
    while (i < end || end == -1)
    {
        if (str[i] == c)
            return 1;
        if(end == -1 && str[i] == '\0')
            break;
        i++;
    }
    return 0;
}

void check (char *s1, char *s2)
{
    int i = 0 ;
    while (s1[i])
    {
        if (was_there(s2, s1[i], -1) && was_there(s1, s1[i], i) == 0)
            write(1,&s1[i], 1);
        i++;
    }
}

int main(int ac, char *av[])
{
    if (ac == 3)
        check(av[1],av[2]);
    write(1, "\n", 1);
    return 0;
}
