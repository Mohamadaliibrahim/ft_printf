#include <unistd.h>

int in_it(char *str,char c,int end)
{
    int i = 0;
    while (i < end)
    {
        if (str[i] == c)
            return 1;
        i++;
    }
    return 0;
}

void    check(char *str1,char *str2)
{
    int i = 0;
    int j = 0;
    while (str1[i])
    {
        if (in_it(str1,str1[i],i) == 0)
            write(1,&str1[i],1);
        i++;
    }
    while(str2[j])
    {
        if (in_it(str2,str2[j],j) == 0 && in_it(str1,str2[j],i) == 0)
            write(1,&str2[j],1);
        j++;
    }
}

int main(int ac, char *av[])
{
    if (ac == 3)
        check(av[1], av[2]);
    write(1, "\n", 1);
    return 0;
}