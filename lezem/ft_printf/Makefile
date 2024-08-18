NAME = libftprintf.a

SOURCES = ft_printf.c ft_check.c ft_utoa.c ft_check1.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_itoa.c

OBJECTS = $(SOURCES:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $@ $^

bonus: $(OBJECTS)
	$(AR) $(NAME) $^

%.o: %.c
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
