/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:49:43 by mohamibr          #+#    #+#             */
/*   Updated: 2024/07/25 12:50:29 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "ft_printf.h"

typedef struct s_node
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*data;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

// Handle errors

// Stack initiation

int	stack_len(t_stack *a);
void	sort_three(t_stack **a);
int	stack_stored(t_stack *a);

// Nodes initiation

// Stack utils

void	sort_three(char *a);

// Commands

char	**ft_split(char *s, char c);

// Algorithms

#endif
