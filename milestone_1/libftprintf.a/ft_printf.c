#include "ft_printf.h"

int ft_printf(const char *hello, ...)
{
    const char *ch;

    ch = (char *)hello;
    va_list arg;
    va_start(arg,hello);
    while(*ch)
    {
        if(*ch == '%' && *(++ch) && *(ch) != '%')
        {
            check_arg(ch,arg);
        }
        else
        {
            ft_putchar_fd(*ch, 1);
        }
        ch++;
    }
    va_end(arg);
}