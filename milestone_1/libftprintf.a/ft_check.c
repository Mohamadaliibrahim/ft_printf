#include "ft_printf.h"
#include "libft.h"

void hexa(char *str, unsigned int x,int z)
{
    int i;
    int j;
    const char *hexa_digits;
    const char *HEXA_DIGITS;
    char buffer[9];

    i = 0;
    hexa_digits = "1234567890abcdef";
    HEXA_DIGITS = "1234567890ABCDEF";
    if (x == 0)
    {
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    else
    {
        while (x > 0)
        {
            if (z == 1)
            {
                buffer[i++] = hexa_digits[x % 16];
            }
            else if (z == 0)
            {
                buffer[i++] = HEXA_DIGITS[x % 16];
            }
            x /= 16;
        }
        j = i - 1;
        while (j >= 0)
        {
            str[i - 1 - j] = buffer[j];
            j--;
        }
    }
    str[i] = '\0';
}

//void HEXA(char *str, unsigned int x)
{
    int i;
    int j;
    char hexa_digits[];
    char HEXA_DIGITS[];
    char buffer[9];

    i = 0;
    HEXA_DIGITS = "1234567890ABCDEF";
    if (x == 0)
    {
        str[0] = 0;
        str[1] = '\0';
        return;
    }
    else
    {
        while (x > 0)
        {
            if ()
            buffer[i++] = hexa_digits[x % 16];
            x /= 16;
        }
        j = i - 1;
        while (j >= 0)
        {
            str[i - 1 - j] = buffer[j];
            j--;
        }
    }
    str[i] = '\0';
}

//void check_arg1(va_list ap, char str)
{
    if (str == 'i' || str == 'd')
        ft_putnbr_fd(va_arg(ap, int), 1);
    else if (str == 'u')
        ft_putnbr_fd(va_arg(ap, unsigned int), 1);
    else if (str == 'x')
    {
        char buffer[9];
        hexa(buffer, va_arg(ap, unsigned long));
        ft_putstr_fd(buffer, 1);
    }
    else if (str == 'X')
    {
        char buffer[9];
        HEXA(buffer, va_arg(ap, unsigned long));
        ft_putstr_fd(buffer, 1);
    }
}

void check_arg(char ch,va_list ap)
{
    int i;
    char buffer[9];

    if (ch == 'c')
        ft_putchar_fd(va_arg(ap, int), 1);
    else if (ch == 's')
        ft_putstr_fd(va_arg(ap, char *), 1);
    else if (ch == 'i' || ch == 'd')
        ft_putnbr_fd(va_arg(ap, int), 1);
    else if (ch == 'u')
        ft_putnbr_fd(va_arg(ap, unsigned int), 1);
    else if (ch == 'x' || ch == 'X')
    {
        if (ch == 'x')
            i = 1;
        else
            i = 0;
        hexa(buffer, va_arg(ap, unsigned long),i);
        ft_putstr_fd(buffer, 1);
    }
}