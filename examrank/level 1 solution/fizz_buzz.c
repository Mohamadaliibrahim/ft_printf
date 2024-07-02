#include <unistd.h>

void ft_putnbr(int i)
{
    char    r[10] = "0123456789";
    if (i > 9)
    {
        ft_putnbr(i/10);
    }
    write(1, &r[i % 10], 1);
}

void check(int i)
{
    while (i <= 100)
    {
        if (i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz", 8);
        else if (i % 3 == 0)
            write(1, "fizz", 4);
        else if (i % 5 == 0)
            write(1,"buzz", 4);
        else
            ft_putnbr(i);
        write(1,"\n", 1);
        i++;
    }
}


int main ()
{
    int i = 1;
    check(i);
    write(1, "\n", 1);
    return 0;
}