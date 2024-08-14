# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 15:38:04 by ajabado           #+#    #+#              #
#    Updated: 2024/06/28 02:11:23 by ajabado          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# color codes
RESET	= \033[0m
BLACK 	= \033[0;30m
RED 	= \033[0;31m
REDB	 = \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[0;33m
YELLOWB = \033[1;33m
BLUE	= \033[0;34m
PURPLE 	= \033[0;35m
CYAN 	= \033[0;36m
WHITE 	= \033[0;37m
HIDE	= \033[?25l
SHOW	= \033[?25h
BOLD	= \033[1m

# character
OBJS_CHAR = $(SRC_CHAR:.c=.o)
SRC_CHAR = $(addprefix $(SRC_DIR)/char/, \
ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c \
ft_toupper.c ft_isspace.c \
)

# linked list
OBJS_LST = $(SRC_LST:.c=.o)
SRC_LST	= $(addprefix $(SRC_DIR)/lst/, \
ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
)

# memory
OBJS_MEM = $(SRC_MEM:.c=.o)
SRC_MEM	= $(addprefix $(SRC_DIR)/mem/, \
ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
ft_memset.c ft_free.c \
)

# conversion
OBJS_CONV = $(SRC_CONV:.c=.o)
SRC_CONV = $(addprefix $(SRC_DIR)/conv/, \
ft_atoi.c ft_itoa.c ft_atol.c ft_nbrlen.c \
)

# character string
OBJS_STR = $(SRC_STR:.c=.o)
SRC_STR	= $(addprefix $(SRC_DIR)/str/, \
ft_split.c ft_strchr.c ft_strdup.c ft_strndup.c \
ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
ft_strcpy.c ft_strlen.c ft_strmapi.c ft_strcmp.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_in.c \
)

# file descriptor
OBJS_PUT = $(SRC_PUT:.c=.o)
SRC_PUT	= $(addprefix $(SRC_DIR)/put/, \
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_puthex_fd.c ft_putunbr_fd.c ft_putptr_fd.c \
)

# printf
OBJS_PRINTF = $(SRC_PRINTF:.c=.o)
SRC_PRINTF = $(addprefix $(SRC_DIR)/printf/, \
ft_printf.c ft_parse.c ft_handle_c.c ft_handle_d.c ft_handle_p.c \
ft_handle_s.c ft_handle_u.c ft_handle_x.c \
)

# get next line
OBJS_GNL = $(SRC_GNL:.c=.o)
SRC_GNL	= $(addprefix $(SRC_DIR)/gnl/, \
get_next_line.c \
)

SRC_DIR	= .
INC_DIR	= ./includes/
CC = gcc
AR = ar
MF = Makefile

FLAGS = -Wall -Wextra -Werror

NAME = libft.a
HEADER	= $(INC_DIR)/libft.h

SRCS = $(SRC_CHAR) $(SRC_LST) $(SRC_MEM) $(SRC_CONV) $(SRC_STR) $(SRC_PUT) $(SRC_PRINTF) $(SRC_GNL)
OBJS = $(OBJS_CHAR) $(OBJS_LST) $(OBJS_MEM) $(OBJS_CONV) $(OBJS_STR) $(OBJS_PUT) $(OBJS_PRINTF) $(OBJS_GNL)

COUNTER = 0
TOTAL_FILES = $(shell echo $$(( $(words $(SRCS)) + 1 )))

all : $(NAME)

$(NAME) : $(MF) $(OBJS) $(HEADER)
	@$(AR) -rcs $(NAME) $(OBJS)
	@echo "\n${GREEN}> Compiled libft successfully$(RESET)$(SHOW)"

clean :
	@rm -f $(OBJS)
	@echo "$(YELLOW)> All objects files of libft have been deleted$(RESET)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(REDB)> Cleaning of libft has been done$(RESET)"

re : fclean all

%.o : %.c $(HEADER) Makefile
	@$(eval COUNTER=$(shell echo $$(($(COUNTER) + 1))))
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR)
	@printf "$(HIDE)$(YELLOWB)\rCompiling libft: $(RESET)["
	@printf "%0.s#" $(shell seq 1 $(COUNTER))
	@if [ $(COUNTER) -lt $(TOTAL_FILES) ]; then \
		printf "%0.s." $(shell seq 1 $$(($(TOTAL_FILES) - $(COUNTER)))); \
	fi
	@printf "] (%d/%d)" $(COUNTER) $(TOTAL_FILES)

.PHONY: all clean fclean re
