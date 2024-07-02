#include <unistd.h>

void    check(char *str1,char *str2)
{
    int i = 0;
    while (str1[i] != '\0')
    {
        int j = 0;
        while (str2[j] != '\0')
        {
            if (str1[i] == str2[j])
            {
                write(1,&str1[i],1)
                break;
            }
            j++;
        }
        i++;
    }
}

int main (int ac,char *av[])
{
    if (ac == 3)
        check(av[1],av[2]);
    write(1, "\n", 1);
    return 0;
}