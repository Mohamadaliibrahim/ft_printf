#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void	lets_push(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*z;

	z = *a;
	ft_printf("lets(a):\n");
	while (z)
	{
		ft_printf("%d\n", z->data);
		z = z->next;
	}
	pb(a, b);
	pb(a, b);
	temp = *b;
	ft_printf("lets(b):\n");
	while (temp)
	{
		ft_printf("b: %d\n", temp->data);
		temp = temp->next;
	}
	//z = *a;
	//while (z)
	//{
	//	ft_printf("a: %d\n", z->data);
	//	z = z->next;
	//}
	free_stack(z);
	free_stack(temp);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	if (!ac)
		return (0);
	a = NULL;
	b = NULL;
	a = create_stack_from_args(ac, av);
	lets_push(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include "ft_printf/ft_printf.h"

typedef struct s_cost
{
	int		min_cost;
	int		best_a;
	int		best_b;
	int		pos_a;
}				t_cost;

typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}				t_stack;

typedef struct s_calc_args
{
	t_stack		*a;
	t_stack		*b;
	int			target;
	int			pos_a;
}				t_calc_args;

void		sort_three(t_stack **a);
void		sort_four(t_stack **a, t_stack **b);
void		sort_five(t_stack **a, t_stack **b);

void		assign_targets(t_stack *a, t_stack *b);
void		move_min_to_top(t_stack *a);
void		push_with_min_cost(t_stack *a, t_stack *b);

int			find_median_index(int size);
int			stack_is_sorted(t_stack *a);
int			stack_len(t_stack *a);
int			get_cost(t_stack *x, int position);
int			a_to_b_find_target(t_stack *b, int value);
int			find_min_value(t_stack *a);

t_stack		*init_stack(void);
t_stack		*create_stack_from_args(int ac, char **av);
t_node		*find_index(t_stack *a, int value);

void		sa(t_stack **a);
void		sb(t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);

void		ft_error(char *msg);
int			ft_isdigit(int c);
char		*ft_substr(const char *s, unsigned int start, size_t len);
int			ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strdup(const char *src);
char		**ft_split(char const *s, char c);
void		free_stack(t_stack *stack);

#endif

// main.c

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (-1);
	ft_check_args(ac, av);
	a = create_stack_from_args(ac, av);
	b = init_stack();
	if (!a || !b)
	{
		ft_error("Error: Failed to initialize stacks.");
		return (1);
	}
	if (stack_is_sorted(a))
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	if (stack_len(a) == 2)
		sa(&a);
	else if (stack_len(a) == 3)
		sort_three(&a);
	else if (stack_len(a) == 4)
		sort_four(&a, &b);
	else if (stack_len(a) == 5)
		sort_five(&a, &b);
	else
	{
		assign_targets(a, b);
		sort_b_to_a(a, b);
		move_min_to_top(a);
	}
	free_stack(a);
	free_stack(b);
	return (0);
}

// stack_utils.c

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

t_stack	*create_stack_from_args(int ac, char **av)
{
	t_stack	*stack;
	t_node	*new_node;
	int		i;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	i = ac - 1;
	while (i >= 1)
	{
		new_node = create_node(atoi(av[i]));
		if (!new_node)
			return (NULL);
		new_node->next = stack->top;
		if (stack->top)
			stack->top->prev = new_node;
		stack->top = new_node;
		stack->size++;
		i--;
	}
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	if (!stack)
		return ;
	while (stack->top)
	{
		temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
	}
	free(stack);
}

// sorting.c

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_node	*x;
	t_node	*y;
	t_node	*z;

	if (!a || !*a || !(*a)->top || !(*a)->top->next || stack_is_sorted(*a))
		return ;
	x = (*a)->top;
	y = x->next;
	z = y->next;
	if (x->value > y->value && y->value < z->value && x->value < z->value)
		sa(a);
	else if (x->value > y->value && y->value > z->value && x->value > z->value)
	{
		sa(a);
		rra(a);
	}
	else if (x->value < y->value && y->value > z->value && x->value < z->value)
	{
		sa(a);
		ra(a);
	}
	else if (x->value > y->value && y->value < z->value && x->value > z->value)
		ra(a);
	else
		rra(a);
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	min;
	t_node	*min_node;

	if (!a || !*a || stack_is_sorted(*a))
		return ;
	min = find_min_value(*a);
	min_node = find_index(*a, min);
	if (min_node == (*a)->top->next)
		ra(a);
	else if (min_node == (*a)->top->next->next)
	{
		ra(a);
		ra(a);
	}
	else if (min_node == (*a)->top->prev)
		rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	if (!a || !*a || stack_is_sorted(*a))
		return ;
	sort_five1(a, b);
	sort_five2(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	move_min_to_top(t_stack *a)
{
	int		min_value;
	int		min_position;
	int		median;

	min_value = find_min_value(a);
	min_position = find_index1(a, min_value);
	median = a->size / 2;
	if (min_position <= median)
		while (min_position-- > 0)
			ra(&a);
	else
		while (min_position++ < a->size)
			rra(&a);
}

// costs.c

#include "push_swap.h"

void	min_cost(t_stack *a, t_stack *b)
{
	t_cost	cost;

	min_cost1(a, b, &cost);
	min_cost4(a, cost.best_a);
	min_cost5(b, cost.best_b);
	pb(&a, &b);
}

void	min_cost1(t_stack *a, t_stack *b, t_cost *cost)
{
	t_node	*current_a;

	cost->min_cost = INT_MAX;
	cost->pos_a = 0;
	current_a = a->top;
	while (current_a)
	{
		min_cost2(a, b, current_a, cost);
		cost->pos_a++;
		current_a = current_a->next;
	}
}

void	min_cost2(t_stack *a, t_stack *b, t_node *current_a, t_cost *cost)
{
	int			target;
	int			cost_a;
	int			cost_b;
	t_calc_args	args;

	target = a_to_b_find_target(b, current_a->value);
	args.a = a;
	args.b = b;
	args.target = target;
	args.pos_a = cost->pos_a;
	min_cost3(&args, &cost_a, &cost_b);
	if (cost_a + cost_b < cost->min_cost)
	{
		cost->min_cost = cost_a + cost_b;
		cost->best_a = cost->pos_a;
		cost->best_b = cost_b;
	}
}

void	push_with_min_cost(t_stack *a, t_stack *b)
{
	t_cost	cost;

	min_cost_b_to_a(a, b);
	push_with_min_cost1(a, &cost);
	push_with_min_cost2(a, &cost);
	push_with_min_cost3(b, &cost);
	pa(&a, &b);
}

// targets.c

#include "push_swap.h"

void	assign_targets(t_stack *a, t_stack *b)
{
	t_node	*current_a;
	t_node	*current_b;

	current_b = b->top;
	while (current_b)
	{
		current_b->target_node = NULL;
		current_a = a->top;
		while (current_a)
		{
			if (current_a->value > current_b->value)
				assign_target_helper(a, current_b, current_a);
			current_a = current_a->next;
		}
		current_b = current_b->next;
	}
}

void	assign_target_helper(t_stack *a, t_node *current_b, t_node *current_a)
{
	if (!current_b->target_node)
		current_b->target_node = current_a;
	else if (current_a->value < current_b->target_node->value)
		current_b->target_node = current_a;
}
