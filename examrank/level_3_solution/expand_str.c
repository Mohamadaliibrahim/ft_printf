#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

void    check(char *str)
{
    int i = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    int start = i;
    i = ft_strlen(str) - 1;
    while (i >= 0)
    {
        if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        {
            i--;
        }
        else
            break;
    }
    int end = i;
    while (start <= end)
    {
        while (str[start] == ' ' || (str[start] >= 9 && str[start] <= 13))
            {
                if ((str[start + 1] != '\0') && !(str[start + 1] == ' ' || (str[start+1] >= 9 && str[start+1] <= 13)))
                    {
                        write(1, "   ", 3);
                    }
                start++;
            }
            write(1, &str[start], 1);
            start++;
    }
}

int main(int ac,char *av[])
{
    if (ac == 2)
        check(av[1]);
    write(1, "\n", 1);
    return 0;
}