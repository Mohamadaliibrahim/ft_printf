#include "ft_printf.h"

int ft_printf(const char *hello, ...)
{
    char *ch;

    ch = (char *)hello;
    va_list arg;
    va_start(arg,hello);
    while(*ch)
    {
        if(*ch == '%' && *(++ch) && *(ch) != '%')
        {
            check_arg(arg,ch);
        }
        else
        {
            ft_putchar_fd(*ch, 1);
        }
        ch++;
    }
    va_end(arg);
}