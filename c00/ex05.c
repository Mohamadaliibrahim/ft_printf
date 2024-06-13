#include <unistd.h>

void ft_putnbr(int a)
{
       if (a > 9)
       {
        ft_putnbr(a/10);
       }    
       a = a%10 + '0';
        write(1, &a, 1);
}

int main()
{
    int i,j,z;
    i = 0;
    while (i <= 7)
    {
        j = i + 1;
        while (j <= 8)
        {
            z = j + 1;
            while (z <= 9)
            {
                ft_putnbr(i);
                ft_putnbr(j);
                ft_putnbr(z);
                write(1, ",", 1);
                z++;
            }
            j++;
        }
        i++;
    }
}