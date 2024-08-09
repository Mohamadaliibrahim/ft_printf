#include <unistd.h>

void putnumber(int c)
{
    char avd[] = "0123456789";
    if (c > 9)
        putnumber(c / 10);
    write(1, &avd[c % 10], 1);
}

int main(int ac, char *av[])
{
    if (ac < 1)
        {
            write(1,"0", 1);
            return (0);
        }
        else
            putnumber(ac - 1);
        write(1, "\n", 1);
        return 0;
}