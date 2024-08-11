CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
EXTRAFLAGS = -lreadline -lncurses

SRC =	check.c check1.c ft_split.c ft_strlcpy.c ft_strlen.c ft_substr.c\
		let_stack_0.c let_stack_1.c push_swap.c reverse_rotate.c\
		rotate.c swap.c push.c ft_strdup.c algorithms.c algorithms1.c\
		algorithms2.c algorithms3.c let_stack_2.c let_stack_3.c 

OBJ = $(SRC:.c=.o)
EXEC = push_swap
LIBDIR = ft_printf
LIB = $(LIBDIR)/libftprintf.a

all: $(LIB) $(EXEC) 

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) $(LIB) $(EXTRAFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -I includes -c $< -o $@

$(LIB):
	$(MAKE) -C $(LIBDIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	rm -f $(EXEC) $(LIB)
	$(MAKE) -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re

