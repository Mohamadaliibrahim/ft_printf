#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

int	stack_len(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	stack_is_sorted(t_stack *a)
{
	int	z;

	if (a == NULL)
		return (1);
	z = a->data;
	a = a->next;
	while (a)
	{
		if (z > a->data)
			return (0);
		z = a->data;
		a = a->next;
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}



t_stack	*create_stack_from_args(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*new_node;
	int		i;

	stack = NULL;
	i = ac - 1;
	while (i >= 1)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->data = atoi(av[i]);
		new_node->next = stack;
		stack = new_node;
		i--;
	}
	return (stack);
}


int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*temp;
	int		sort;
	int		len;
	int		i;

	if (!ac)
		return (0);
	a = NULL;
	i = 0;
	a = create_stack_from_args(ac, av);
	sort = stack_is_sorted(a);
	printf("sorted = %d\n", sort);
	len = stack_len(a);
	printf("len = %d\n", len);
	if (sort == 0 && len == 3)
	{
		sort_three(&a);
		temp = a;
		while (temp)
		{
			printf("%d\n", temp->data);
			temp = temp->next;
		}
	}
	free_stack(a);
	return (0);
}
