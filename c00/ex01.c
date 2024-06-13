#include <unistd.h>

int main()
{
    write(1,"abcdefghijklmnopqrstuvwxyz\n",27);
    return 0;
}