/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:05:47 by mohamibr          #+#    #+#             */
/*   Updated: 2024/08/02 20:05:51 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib_ft/libft.h"
# include "printf/ft_printf.h"

/* Stack */
typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}				t_stack;

/* Util functions */
t_stack	*ft_lstnew(int data);
t_stack	*ft_lstlast(t_stack *head);
void	ft_lstadd_front(t_stack **stack, t_stack *new);
void	ft_lstadd_back(t_stack **stack, t_stack *new);
void	print_stack(t_stack *head);
int		ft_lstsize(t_stack *head);

void	ft_error(char *msg);
void	ft_check_args(int ac, char **av);
int		is_sorted(t_stack **stack);
int		get_distance(t_stack **stack, int index);
void	make_top(t_stack **stack, int distance);
void	free_stack(t_stack **stack);
void	ft_free(char **str);

/* Algorithm utils */
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
void	simple_sort(t_stack **stack_a, t_stack **stack_b);
void	index_stack(t_stack **stack);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
int		get_min(t_stack **stack, int val);
void	sort_3(t_stack **stack_a);

/* Instruction functions */
int		swap(t_stack **stack);
int		push(t_stack **stack_to, t_stack **stack_from);
int		rotate(t_stack **stack);
int		reverse_rotate(t_stack **stack);

int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_b, t_stack **stack_a);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);

/* Custom functions */
void	free_split(char **split);
void	ft_validate_args(char **av, int flag, int i);

#endif
