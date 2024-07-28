NAME                = push_swap
CC                  = gcc
CFLAGS              = -Wall -Wextra -Werror
RM                  = rm -f

SOURCES = \
	ft_strlen.c   ft_putendl_fd.c  \
	ft_printf.c ft_check.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
	ft_utoa.c ft_itoa.c ft_strdup.c ft_check1.c a_to_b.c b_to_a.c error.c push_swap.c \
	push.c rev_rotate.c rotate.c sort_3.c sort_it.c split.c stack_uti.c stackin_it.c \
	swap_it.c ft_isdigit.c\

OBJS = $(SOURCES:.c=.o)

start:
	@make all

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: start all clean fclean re
