# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 22:53:03 by fbicandy          #+#    #+#              #
#    Updated: 2024/08/18 13:46:03 by fbicandy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
INCLUDES = ./ 
PRINTF = ./libraries/ft_printf/libftprintf.a
LIBFTDIR = ./libraries/ft_printf

CC = gcc
CFLAGS = -Wall -Werror -Wextra

BONUS = ./bonus/checker.c ./bonus/get_next_line/get_next_line.c ./bonus/get_next_line/get_next_line_utils.c \
		./bonus/get_next_line/get_next_line.c ./bonus/get_next_line/get_next_line_utils.c \

SRCS = main.c \
	src/operations/ps.c src/operations/rrs.c src/operations/rs.c src/operations/sw.c \
	src/checker.c src/push_swap_utils.c src/push_swap.c src/sa_sort.c src/sb_sort.c src/sort_utils.c src/stack.c \
	libraries/ft_atoi.c libraries/ft_itoa.c libraries/ft_isdigit.c libraries/ft_split.c  libraries/ft_strjoin.c

OBJECTS = $(SRCS:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)


all: $(NAME)

bonus: $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(PRINTF)  -o CHECKER


$(NAME): $(OBJECTS) $(PRINTF) 
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME) $(PRINTF) 

$(PRINTF):	
	@make -C ./libraries/ft_printf

z: all bonus clean

clean:	
	@make clean -C ./libraries/ft_printf
	rm -f $(OBJECTS) $(BONUS_OBJ)
	@clear
fclean: clean
	@make fclean -C ./libraries/ft_printf 
	rm -f $(NAME)
	rm -f CHECKER
re: fclean all
.PHONY: all bonus clean fclean re