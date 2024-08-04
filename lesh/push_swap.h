#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

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

void	sort_three_1(t_stack **a,);
void	sort_three(t_stack **a,);

		/*Error_check*/

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

#endif
