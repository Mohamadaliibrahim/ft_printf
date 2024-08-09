#include <unistd.h>

void    check(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if(str[i] >= 'a' && str[i] <= 'z')
			str[i] = 'z' - str[i] + 'a';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = 'Z' - str[i] + 'A';
		write(1, &str[i], 1);
        i++;
    }
}

int main(int ac,char *av[])
{
    if (ac == 2)
        check (av[1]);
    write(1, "\n", 1);
    return 0;
}