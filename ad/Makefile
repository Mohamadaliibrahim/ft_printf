# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajabado <ajabado@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/30 15:46:23 by ajabado           #+#    #+#              #
#    Updated: 2024/07/01 19:51:19 by ajabado          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# color codes
END=\033[0m
BOLD=\033[1m
UNDER=\033[4m
REV=\033[7m
GREY=\033[30m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
PURPLE=\033[35m
CYAN=\033[36m
WHITE=\033[37m
HIDE=\033[?25l
SHOW=\033[?25h

# utils
OBJS_UTIL = $(SRC_UTIL:.c=.o)
SRC_UTIL = $(addprefix $(SRC_DIR)/utils/, \
ft_error_print.c find_utils.c ft_rotate_push.c \
ft_rotate_type.c solver_utils_ab.c solver_utils_ba.c \
)

# stack
OBJS_STACK = $(SRC_STACK:.c=.o)
SRC_STACK = $(addprefix $(SRC_DIR)/stack/, \
ft_check_dup.c ft_is_sorted.c ft_stack_add_back.c \
ft_stack_clear.c ft_stack_new.c stack_utils.c \
)

# operations
OBJS_OP = $(SRC_OP:.c=.o)
SRC_OP = $(addprefix $(SRC_DIR)/operations/, \
operations_1.c operations_2.c operations_3.c \
)

# main
OBJS_MAIN = $(SRC_MAIN:.c=.o)
SRC_MAIN = $(addprefix $(SRC_DIR)/main/, \
sorting.c parsing.c \
)

# push_swap
NAME = push_swap
OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)
SRC_PUSH_SWAP = $(addprefix $(SRC_DIR)/main/, \
main.c \
)

# checker
CHECKER = checker
OBJS_CHECKER = $(SRC_CHECKER:.c=.o)
SRC_CHECKER = $(addprefix $(SRC_DIR)/checker/, \
checker.c \
)

SRC_DIR = ./src/
INC_DIR = includes/
HEADER	= $(INC_DIR)/push_swap.h
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

OBJS = $(OBJS_MAIN) $(OBJS_OP) $(OBJS_STACK) $(OBJS_UTIL)

all: $(LIBFT) $(NAME)
	@/bin/echo -e "$(BOLD)$(GREEN)> Compiled push_swap successfully$(END)$(SHOW)"

bonus: $(LIBFT) $(OBJS) $(CHECKER)
	@/bin/echo -e "$(BOLD)$(GREEN)> Compiled checker successfully$(END)$(SHOW)"

$(NAME): $(OBJ_PUSH_SWAP) $(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJS) $(OBJ_PUSH_SWAP) $(LIBFT) -o $(NAME)
	@/bin/echo ""

$(CHECKER): $(OBJS_CHECKER) $(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJS) $(OBJS_CHECKER) $(LIBFT) -o $(CHECKER)
	@/bin/echo ""

$(LIBFT):
	@make -C $(LIBFT_DIR)

COUNTER = 0
TOTAL_FILES = $(shell echo $$(($(words $(OBJS)) + $(words $(OBJ_PUSH_SWAP)))))

%.o : %.c $(HEADER) Makefile
	@/bin/echo -en "$(HIDE)"
	@$(eval COUNTER=$(shell echo $$(($(COUNTER) + 1))))
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR)
	@/bin/echo -en "$(BOLD)$(YELLOW)\rCompiling push_swap: $(END)["
	@printf "%0.s#" $(shell seq 1 $(COUNTER))
	@if [ $(COUNTER) -lt $(TOTAL_FILES) ]; then \
		printf "%0.s." $(shell seq 1 $$(($(TOTAL_FILES) - $(COUNTER)))); \
	fi
	@printf "] (%d/%d)" $(COUNTER) $(TOTAL_FILES)

clean:
	@$(RM) $(OBJS) $(OBJ_PUSH_SWAP) $(OBJS_CHECKER)
	@make clean -C $(LIBFT_DIR)
	@/bin/echo -e "$(YELLOW)> All object files of push_swap have been deleted$(END)$(SHOW)"

fclean:
	@$(RM) $(OBJS) $(OBJ_PUSH_SWAP) $(OBJS_CHECKER)
	@$(RM) $(NAME) $(CHECKER)
	@make fclean -C $(LIBFT_DIR)
	@/bin/echo -e "$(YELLOW)> All object files of push_swap have been deleted$(END)"
	@/bin/echo -e "$(BOLD)$(GREEN)> Cleaning of push_swap has been done$(END)$(SHOW)"

re: clean all

.PHONY: all clean fclean re bonus
