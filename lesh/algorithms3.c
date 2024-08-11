#include "push_swap.h"

int	find_median_index(int size)
{
	if (size % 2 == 0)
		return (size / 2);
	else
		return (size / 2 + 1);
}
