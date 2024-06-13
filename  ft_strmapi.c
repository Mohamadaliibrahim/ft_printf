#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    int len;
    int i;
    char *ch;

    if (!s || !f)
        return (NULL);
    len = ft_strlen(s);
    i = 0;
    ch = (char *)malloc(sizeof(char) * (len + 1));
    if (ch == NULL)
        return (NULL);
    while (s[i] != '\0')
    {
        ch[i] = f(i, s[i]);
        i++;
    }
    ch[i] = '\0';
    return ch;
}
