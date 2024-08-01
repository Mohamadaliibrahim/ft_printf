NAME                = push_swap
CC                  = gcc
CFLAGS              = -Wall -Wextra -Werror -g
RM                  = rm -f

SOURCES = \
    a_to_b.c b_to_a.c error.c ft_atoi.c push_swap.c\
    rev_rotate.c rotate.c sort_3.c sort_it.c split.c\
    stack_uti.c stackin_it.c swap_it.c ft_strdup.c\
    ft_isdigit.c push.c

OBJS = $(SOURCES:.c=.o)

EXTRAFLAGS = -lreadline -lncurses

EXEC = push_swap
LIBDIR = printf
LIB = libftprintf.a

all: $(LIBDIR)/$(LIB) $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) $(LIB) $(EXTRAFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -I includes -c $< -o $@

$(LIBDIR)/$(LIB):
	$(MAKE) -C $(LIBDIR)
	cp $(LIBDIR)/$(LIB) .

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	$(RM) $(EXEC) $(LIB)
	$(MAKE) -C $(LIBDIR) fclean
