#include <unistd.h>

int ft_atoi(char *str)
{
    int i = 0;
    int r = 0;
    while (str[i])
    {
        r = r * 10 + str[i] - '0';
        i++;
    }
    return r;
}

void ft_print_hex(int z)
{
    char hey[] = "0123456789abcdef";
    if (z > 16)
        ft_print_hex(z / 16);
    write(1, &hey[z % 16], 1);   
}

void    check_hex(char *str)
{
    int c = ft_atoi(str);
    if (c == 0)
        return ;
    ft_print_hex(c);    
}

int main (int ac,char *av[])
{
    if (ac == 2)
        check_hex(av[1]);
    write(1, "\n", 1);
    return 0;
}