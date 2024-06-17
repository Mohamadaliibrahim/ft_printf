#include "ft_printf.h"

int ft_printf(const char *hello, ...)
{
    va_list arg;
    va_start(arg,hello);
    check_arg(arg,(char *)hello);
    va_end(arg);
}