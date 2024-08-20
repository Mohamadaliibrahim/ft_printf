/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:25:23 by mohamibr          #+#    #+#             */
/*   Updated: 2024/08/19 10:25:28 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include "ft_printf/ft_printf.h"
# include <stdbool.h>

typedef struct s_parse_info
{
	size_t	i;
	int		neg;
	int		flag;
	char	**av;
}	t_parse_info;

typedef struct s_stack
{
	int					data;
	int					index;
	int					cost;
	int					cheapest;
	bool				above_median;
	struct s_stack		*target_node;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

/* Algorithm */
void	sort_three_1(t_stack **a);
void	sort_three(t_stack **a);
t_stack	*push_swap(t_stack **stack_a, t_stack **stack_b, int size_a);
t_stack	*get_cheapest(t_stack *stack);
void	move_a_to_b(t_stack **a, t_stack **b);
void	init_node_a(t_stack **a, t_stack **b);
t_stack	*set_target_nodes_b(t_stack *stack_a, t_stack *stack_b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	init_node_b(t_stack **a, t_stack **b);
int		stack_is_empty(t_stack *stack);
void	finish_program(t_stack *a, t_stack *b);
t_stack	*find_smallest(t_stack *stack);
void	current_index(t_stack *stack);
t_stack	*set_cheapest(t_stack *stack);
void	bring_on_top(t_stack **stack, t_stack *desired_node, char stack_name);
t_stack	*cost_analyst(t_stack *stack_a, t_stack *stack_b);
t_stack	*set_target_nodes_a(t_stack *stack_a, t_stack *stack_b);
t_stack	*find_max_node(t_stack *stack);

/* Error_check && Utils */
int		ft_isdigit(int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
void	free_it(char **str);
int		check(char *av[]);
int		stack_is_sorted(t_stack *a);
t_stack	*create_stack_from_args(int ac, char **av);
char	**prepare_arguments(int ac, char **av, int *new_ac, char ***split_args);
void	link_new_node(t_stack *new_node, t_stack **stack);
int		check_value_bounds(long value, t_stack **stack);
int		add_node_to_stack(char *arg, t_stack **stack);
int		build_stack(int ac, char **av, t_stack **stack);
void	free_stack(t_stack *stack);
int		stack_len(t_stack *a);
void	ft_error(char *msg);
int		ft_isnum(char *num);
int		ft_contains(int num, char **av, int i, int flag);
void	ft_check_args(int ac, char **av);
long	convert_to_long(char *nptr, size_t i, int neg);
void	check_sign_and_whitespace(char *nptr, t_parse_info *info);
long	ft_atoi(char *nptr, char **av, int flag);
t_stack	*create_node(int value);

/* Operations */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);

#endif
