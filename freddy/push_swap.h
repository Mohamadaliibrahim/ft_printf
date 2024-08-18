/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:32:50 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/17 00:17:41 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "./libraries/ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	int					data;
	int					index;
	int					cost;
	bool				cheapest;
	bool				above_median;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

void			print_stack(t_stack_node *stack);
void			diff(t_stack_node *sa, t_stack_node *sb);

// sa sort
void			init_node_a(t_stack_node **a, t_stack_node **b);
void			move_a_to_b(t_stack_node **a, t_stack_node **b);
// sb sort
void			init_node_b(t_stack_node **a, t_stack_node **b);
void			move_b_to_a(t_stack_node **b, t_stack_node **a);
// pushswap utils
t_stack_node	*set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
t_stack_node	*cost_analyst(t_stack_node *stack_a, t_stack_node *stack_b);
// pushswap
void			bring_on_top(t_stack_node **stack,
					t_stack_node *desired_node, char stack_name);
void			current_index(t_stack_node *stack);
t_stack_node	*push_swap(t_stack_node *sa, t_stack_node *sb, int size_a);
t_stack_node	*tinysort(t_stack_node *sa);
int				sorted(t_stack_node *sa);
// sort utils
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*find_biggest(t_stack_node *stack);
t_stack_node	*stack_store(char **tabs);
t_stack_node	*find_smallest(t_stack_node *stack);
void			sort(t_stack_node *sa, t_stack_node *sb);
int				stack_size(t_stack_node *sa);
// libraries/
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_atoi(const char *str);
int				ft_printf(const char *input, ...);
int				ft_isdigit(unsigned char get_chars);
// src/
void			free_array(char **array);
void			free_stack(t_stack_node *stack);
void			print_stack(t_stack_node *stack);
int				ft_isduplicate(char **argv, int argc);
int				ft_size(char **tabs);
int				invalid_int(char *s);
// operations
void			ps(t_stack_node **src, t_stack_node **dest, char c);
t_stack_node	*sw(t_stack_node *stack, char c);
void			ss(t_stack_node **sa, t_stack_node **sb);
t_stack_node	*rs(t_stack_node *stack, char c);
void			rr(t_stack_node **sa, t_stack_node **sb);
t_stack_node	*rrs(t_stack_node *stack, char c);
void			rrr(t_stack_node **sa, t_stack_node **sb);

#endif