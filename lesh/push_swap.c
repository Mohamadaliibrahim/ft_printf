#include "push_swap.h"

void	finish_program(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	exit(0);
}

void	rotate_to_min(t_stack **a)
{
	int	min_index;
	int	median_line;

	min_index = find_min_value(*a);
	median_line = stack_len(*a) / 2;
	if (min_index > median_line)
		while (min_index++ < stack_len(*a))
			rra(a);
	else
		while (min_index-- > 0)
			ra(a);
}

void	stack_3_and_b(t_stack **a, t_stack **b)
{
	if (stack_len(*a) == 3 && !stack_is_sorted(*a))
		sort_three(a);
	
	if (stack_len(*a) > 3)
		pb(a, b);

	if (stack_len(*a) == 3)
	{
		sort_three(a);
		rotate_to_min(a);
	}

	push_to_target(a, b);
}


void do_it(t_stack **a, t_stack **b)
{
    pb(a, b);
    if (stack_len(*a) == 3)
	{
        stack_3_and_b(a, b);
		//finish_program(*a, *b);
	}
    pb(a, b);
    if (stack_len(*a) == 3)
	{
        stack_3_and_b(a, b);
		//finish_program(*a, *b);
	}
	//else
	//{
	//	ft_printf("hello\n");
	//	finish_program(*a, *b);
	//}
}

void	push_swap_it(t_stack **a,t_stack **b)
{
	if (stack_len(*a) == 4 || stack_len(*a) == 5)
		do_it(a, b);
	else
	{
		while (stack_len(*a) > 3)
		{
			push_min_cost(a, b);
		}
		sort_three(a);
		stack_3_and_b(a, b);
	}
}

int main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*t;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (-1);
	ft_check_args(ac, av);
	a = create_stack_from_args(ac, av);
	b = init_stack();
	if (a == NULL || b == NULL)
	{
		ft_error("Error: Failed to initialize stacks.");
		return (1);
	}
	if (stack_is_sorted(a))
		finish_program(a, b);
	if (stack_len(a) == 2)
		sa(&a);
	ft_printf ("ade:%d\n", stack_len(a));
	if (stack_len(a) == 3)
		sort_three(&a);
	else
	{
		push_swap_it(&a, &b);
	}
	t = a;
	ft_printf("Sorted stack:\n");
	while (t)
	{
		ft_printf("%d\n", t->data);  // Debug print
		t = t->next;
	}
	free_stack(a);
	free_stack(b);
	return (0);
}

/*
Okay, I want you to create me a function in language C. So that's a function that has two stacks, stack A and stack B.
 So it searches for each number in stack A, its target in stack B. So
 the number in stack A has a target in stack B. So what is its target? The target here 
is that the number in stack A is closest, smaller, or closest minimum in stack B. Like in stack A, there's a 
number 5. The closest minimum to number 5 is 4, for example. Get it? If there is no closest smaller,
 then the maximum number in the stack B is the target of the number in stack A. Okay, and when we 
search for all the stacks, okay, we search for all the targets in the stack. What we'll do now,
 we will get the cost for each 
stack. The cost is for every reverse rotate or rotate or swap in both stacks, we add them together,
 and after that, we create the cost. Every rotate, it will get into the cost, or reverse rotate, or swap,
 or additional stuff like that. Then we will push, or we will push from stack A to stack B the minimum cost.
 What does that mean? Like, after finding that number that has the minimum cost of the push,
 we take the target of it and do the reverse rotate, or the rotate, or the swap, depends on the case,
  and put it on the top of the stack.
 We need to do all of that. At first, we have two stacks, stack A numbers and stack B numbers.
 For every number in stack A, we want to find the target in stack B, and when finding the target,
 we need to calculate the reverse rotate, or any rotate, normal rotate, or swap that will be done to push that number,
 and we calculate the cost. After calculating the cost, we will push the minimum cost in all the numbers,
 in all the tests that we made. After pointing on the number that we want to be pushed,
 we put the number up to the top of the stack in stack A, and its target up to the top of the stack in stack B.
 Then the number in stack A should be pushed up on top of its target in stack B.
 After that, we repeat that as many times as stack A has three numbers only. If it has four numbers,
 we will want to push the minimum cost. If it has three numbers, we will stop. Get it? Can you help me with that?
 I will give you some utils and header files and stuff like that. You can use them. The push function, we have it.
 The reverse function, we have it. The swap function, we have it. And the rotate function,
 we have it. Okay? So you just make the target and the cost function that these are the algorithm in it.

 #ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
    int					data;
    int					cost;
    struct s_stack		*target;
    struct s_stack		*next;
    struct s_stack		*prev;
}	t_stack;

/* Algorithm */
void	sort_three_1(t_stack **a);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	sort_five1(t_stack **a, t_stack **b);
void	sort_five2(t_stack **a, t_stack **b);
int		find_index1(t_stack *stack, int value);
int		find_min_value(t_stack *stack);
t_stack	*find_target(t_stack *b, int value);
int		calculate_cost(t_stack *a, t_stack *b, t_stack *target);
void	push_min_cost(t_stack **a, t_stack **b);
void	move_value_to_top(t_stack **stack, int value);

/* Error_check */
int		median_line(t_stack *stack);

void	ft_error(char *msg);
int		ft_isdigit(int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	free_it(char **str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		check(char *av[]);
void	lets_free(char **str);
char	**ft_split(char const *s, char c);
int		stack_is_sorted(t_stack *a);
t_stack	*create_stack_from_args(int ac, char **av);
void	free_stack(t_stack *stack);
int		stack_len(t_stack *a);

/* Operations */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);

/* Utils */
int		min(int a, int b);
int		abs(int n);
void	ft_check_args(int ac, char **av);
void	ft_validate_args(char **av, int flag, int i);
int		ft_isnum(char *num);
long	ft_atoi(const char *nptr);
int		ft_contains(int num, char **av, int i);
void	ft_error(char *msg);
void	ft_putendl_fd(char *s, int fd);
int		ft_isdigit(int c);

int		find_median_line(t_stack *stack);
t_stack	*init_stack(void);

/* Chat */
void	push_value_to_target_position(int value_in_b, t_stack **a, t_stack **b);
void	push_and_sort_two(t_stack **a, t_stack **b);
int		calculate_cost(t_stack *a, t_stack *b, t_stack *target);
t_stack	*find_target(t_stack *b, int value);
void	push_min_cost(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	assign_targets(t_stack *a, t_stack *b);
void	sort_b_to_a(t_stack *a, t_stack *b);
void	move_value_to_top(t_stack **stack, int value);

void	push_to_target(t_stack **a, t_stack **b);
int		find_target_index(t_stack *a, int b_data);
int 	find_min_index(t_stack *a);

int		stack_is_empty(t_stack *stack);
int		find_max_value(t_stack *stack);
int		find_position(t_stack *stack, int value);

#endif
*/
#include "push_swap.h"

// Function to find the closest smaller number in stack B or the maximum if none exists
t_stack *find_target(t_stack *b, int value) {
    t_stack *target = NULL;
    t_stack *current = b;
    int max_value = INT_MIN;

    while (current) {
        if (current->data < value && (!target || current->data > target->data)) {
            target = current;
        }
        if (current->data > max_value) {
            max_value = current->data;
        }
        current = current->next;
    }

    if (!target) {
        current = b;
        while (current) {
            if (current->data == max_value) {
                target = current;
                break;
            }
            current = current->next;
        }
    }

    return target;
}

// Function to calculate the cost of moving a number to the top of stack A and its target to the top of stack B
int calculate_cost(t_stack *a, t_stack *b, t_stack *target) {
    int cost = 0;
    t_stack *current = a;

    // Calculate cost to move the number to the top of stack A
    while (current && current->data != target->data) {
        cost++;
        current = current->next;
    }

    // Calculate cost to move the target to the top of stack B
    current = b;
    while (current && current->data != target->data) {
        cost++;
        current = current->next;
    }

    return cost;
}

// Function to push the number with the minimum cost from stack A to stack B
void push_min_cost(t_stack **a, t_stack **b) {
    t_stack *current = *a;
    t_stack *min_cost_node = NULL;
    t_stack *target = NULL;
    int min_cost = INT_MAX;

    // Find the number with the minimum cost
    while (current) {
        t_stack *current_target = find_target(*b, current->data);
        int cost = calculate_cost(*a, *b, current_target);
        if (cost < min_cost) {
            min_cost = cost;
            min_cost_node = current;
            target = current_target;
        }
        current = current->next;
    }

    // Move the number and its target to the top of their respective stacks
    move_value_to_top(a, min_cost_node->data);
    move_value_to_top(b, target->data);

    // Push the number from stack A to stack B
    pb(a, b);
}

// Function to move a value to the top of the stack
void move_value_to_top(t_stack **stack, int value) {
    t_stack *current = *stack;
    int position = 0;

    // Find the position of the value in the stack
    while (current && current->data != value) {
        position++;
        current = current->next;
    }

    // Rotate or reverse rotate to move the value to the top
    if (position <= stack_len(*stack) / 2) {
        while ((*stack)->data != value) {
            ra(stack);
        }
    } else {
        while ((*stack)->data != value) {
            rra(stack);
        }
    }
}

// Main function to perform the sorting algorithm
void sort_stacks(t_stack **a, t_stack **b) {
    while (stack_len(*a) > 3) {
        push_min_cost(a, b);
    }
    // Sort the remaining three numbers in stack A
    sort_three(a);
}