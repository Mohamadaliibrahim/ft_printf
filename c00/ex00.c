#include <unistd.h>

int main()
{
    write(1, "X\n", 2);
    //write(1, "/n",1);
    return 0;
}