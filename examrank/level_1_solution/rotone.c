#include <unistd.h>

void    lower(char c)
{
    if (c == 'z')
    {
		c = 'a';
		write(1, &c, 1);
		return ;
    }
	else
		c += 1;
	write(1, &c, 1);
}

void    upper(char c)
{
    if (c == 'Z')
    {
		c = 'A';
		write(1, &c, 1);
		return ;
    }
	else
		c += 1;
	write(1, &c, 1);
}

void    check(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            lower(str[i]);
        else if (str[i] >= 'A' && str[i] <= 'Z')
            upper(str[i]);
        else
            write(1, &str[i], 1);
        i++;
    }
}

int main(int ac,char *av[])
{
    if(ac < 2)
    {
        write(1, "\n", 1);
        return 0;
    }
    else
        check (av[1]);
    write(1, "\n", 1);
    return 0;
}