#include "libft.h"
#include "ft_printf.h"

// Function to get the length of the string representation of the unsigned integer
static int get_unsigned_length(unsigned int n)
{
    int length = 1;
    while (n /= 10)
        length++;
    return length;
}

char *ft_utoa(unsigned int n)
{
    int length = get_unsigned_length(n);
    char *str = (char *)malloc(length + 1); // Allocate memory for the string
    if (!str)
        return NULL;
    
    str[length] = '\0'; // Null-terminate the string

    while (length--)
    {
        str[length] = (n % 10) + '0'; // Convert the last digit to a character
        n /= 10; // Remove the last digit
    }

    return str;
}
