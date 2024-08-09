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
	int min_cost;    // The current minimum cost found
	int best_a;      // The best position in stack A
	int best_b;      // The best position in stack B
	int pos_a;       // The current position in stack A being evaluated
}	t_cost;


typedef struct s_node
{
	int					value;
	int					index;
	int					cost;
	struct s_node		*target_node;
	struct s_node		*next;
	struct s_node		*prev;
}	t_node;

typedef struct s_stack
{
	t_node				*top;
	int					size;
}	t_stack;

typedef struct s_calc_args
{
	t_stack *a;   // Pointer to stack A
	t_stack *b;   // Pointer to stack B
	int target;   // The target value in stack B corresponding to a value in stack A
	int pos_a;    // The current position in stack A being evaluated
}	t_calc_args;

		/*Algorithm*/

void	lets_continue(t_stack *a, t_stack *b);
void	sort_three_1(t_stack **a);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	sort_five1(t_stack **a, t_stack **b);
void	sort_five2(t_stack **a, t_stack **b);
void	min_cost(t_stack *a, t_stack *b);
void	min_cost_b_to_a(t_stack *a, t_stack *b);
void	min_cost1(t_stack *a, t_stack *b, t_cost *cost);
void	min_cost2(t_stack *a, t_stack *b, t_node *current_a, t_cost	*cost);
void	min_cost3(t_calc_args *args, int *cost_a, int *cost_b);
void	min_cost4(t_stack *a, int best_position_a);
void	min_cost5(t_stack *b, int best_position_b);
int		find_median_index(int size);
void	push_with_min_cost(t_stack *a, t_stack *b);
void	push_with_min_cost1(t_stack *a, t_cost *cost);
void	push_with_min_cost2(t_stack *a, t_cost *cost);
void	push_with_min_cost3(t_stack *b, t_cost *cost);
void	sort_b_to_a(t_stack *a, t_stack *b);
void	move_min_to_top(t_stack *a);
void	assign_targets(t_stack *a, t_stack *b);
t_node	*find_index(t_stack *a, int value);
int		a_to_b_find_target(t_stack *b, int value);
int		get_cost(t_stack *x, int position);
		/*Error_check*/

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

		/*Operations*/

void	sa(t_stack **a);
void	sb(t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);

		/*Utils*/

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

int		find_min_value(t_stack *a);



#endif
