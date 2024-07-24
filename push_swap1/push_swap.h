#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <unistd.h>
#include <stdlib.h>
#include "libftprintf.a\ft_printf.h"
#include "lib_ft\libft.h"

typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack {
    t_node *top;
} t_stack;

int	ra(t_stack *a);

#endif
