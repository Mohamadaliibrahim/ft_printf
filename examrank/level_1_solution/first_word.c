#include <unistd.h>

void	first_word(char *str)
{
	int i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		if (str[i] == ' ')
			break;
		i++;
	}
}

int main(int ac, char *av[])
{
	if (ac < 2)
		return 0;
	else
		first_word(av[1]);
		write(1, "\n", 1);
	return (0);
}