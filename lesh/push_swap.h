#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int					data;
	int					index;
	int					cost;
	struct s_stack		*target_node;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

		/*Algorithm*/

void	sort_three_1(t_stack **a);
void	sort_three(t_stack **a);

		/*Error_check*/

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

		/*Rules*/

void	sa(t_stack **a);
void	sb(t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);







void	ft_check_args(int ac, char **av);
void	ft_validate_args(char **av, int flag, int i);
int		ft_isnum(char *num);
long	ft_atoi(const char *nptr);
int		ft_contains(int num, char **av, int i);
void	ft_error(char *msg);
void	ft_putendl_fd(char *s, int fd);
int		ft_isdigit(int c);




#endif
