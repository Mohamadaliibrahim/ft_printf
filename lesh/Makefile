CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC =	check.c check1.c ft_split.c ft_strlcpy.c ft_strlen.c\
		ft_substr.c utils.c utils1.c push_swap.c reverse_rotate.c\
		rotate.c swap.c push.c ft_strdup.c a_to_b.c b_to_a.c\
		else_it.c utils2.c cheapest_one.c

OBJ = $(SRC:.c=.o)
NAME = push_swap
LIBDIR = ft_printf
LIB = $(LIBDIR)/libftprintf.a

all: $(LIB) $(NAME) 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) $(EXTRAFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -I includes -c $< -o $@

$(LIB):
	$(MAKE) -C $(LIBDIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	rm -f $(NAME) $(LIB)
	$(MAKE) -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re

