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


		/*Algorithm*/

void	sort_three_1(t_stack **a);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	sort_five1(t_stack **a, t_stack **b);
void	sort_five2(t_stack **a, t_stack **b);
int		find_index1(t_stack *stack, int value);
int		find_min_value(t_stack *stack);

		/*Error_check*/
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

int		find_median_line(t_stack *stack);
t_stack	*init_stack(void);

//chat
void	push_value_to_target_position(int value_in_b, t_stack **a, t_stack **b);
void	push_and_sort_two(t_stack **a, t_stack **b);
int		calculate_cost(t_stack *a, t_stack *b, int target);
int		find_target(t_stack *b, int value);
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