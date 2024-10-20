NAME = libftprintf.a

SOURCES = srcs/ft_printf.c \
		  srcs/ft_check.c \
		  srcs/ft_putchar_fd.c \
		  srcs/ft_putstr_fd.c \
		  srcs/ft_putnbr_fd.c \
		  srcs/ft_strlen.c \
		  srcs/ft_utoa.c \
		  srcs/ft_itoa.c \
		  srcs/ft_strdup.c \
		  srcs/ft_check1.c

OBJECTS = $(SOURCES:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $@ $(OBJECTS)

srcs%.o: srcs%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)		

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re