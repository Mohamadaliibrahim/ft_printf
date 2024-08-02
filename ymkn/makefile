NAME = push_swap

SRCS =  main.c stack1.c stack2.c stack3.c stack4.c stack5.c stack6.c\
		stack7.c stack8.c stack9.c stack10.c 

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes

RM = rm -rf

LIBFT_DIR = ./lib_ft
PRINTF_DIR = ./printf

LIBFT = ${LIBFT_DIR}/libft.a
PRINTF = ${PRINTF_DIR}/libftprintf.a

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT} ${PRINTF}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${PRINTF} -o ${NAME}

${LIBFT}:
	@${MAKE} -C ${LIBFT_DIR}

${PRINTF}:
	@${MAKE} -C ${PRINTF_DIR}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	@${MAKE} -C ${LIBFT_DIR} clean
	@${MAKE} -C ${PRINTF_DIR} clean
	@${RM} ${OBJS}

fclean: clean
	@${MAKE} -C ${LIBFT_DIR} fclean
	@${MAKE} -C ${PRINTF_DIR} fclean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
