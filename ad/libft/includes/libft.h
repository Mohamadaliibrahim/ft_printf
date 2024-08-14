/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:45:53 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/28 13:34:34 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>

// linked list type
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

// linked list functions
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// character functions
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_isspace(int c);

// memory functions
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t num, size_t size);
void		ft_free(void *ptr);

// conversion functions
int			ft_nbrlen(int n);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
long		ft_atol(const char *str);

// file description functions
int			ft_putchar_fd(char c, int fd);
int			ft_putstr_fd(char *s, int fd);
int			ft_putendl_fd(char *s, int fd);
int			ft_putnbr_fd(int n, int fd);

// character string functions
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strndup(const char *s1, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strcpy(char *dst, const char *src);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

// printf
typedef struct s_format
{
	char	*flags;
	int		width;
	int		precision;
	char	specifier;
}	t_format;

int			ft_printf(const char *format, ...);
int			ft_in(const char s, const char *set);
int			ft_putunbr_fd(unsigned int n, int fd);
int			ft_puthex_fd(unsigned int num, int fd, char format);
int			ft_putptr_fd(unsigned long long num, int fd);
t_format	ft_format(char **ptr);
char		*parse_flags(char **ptr);
int			parse_width(char **ptr);
int			parse_precision(char **ptr);
char		parse_specifier(char **ptr);
int			ft_handle_s(t_format *s_format, const char *str);
int			ft_handle_c(t_format *s_format, const char c);
int			ft_handle_p(t_format *s_format, unsigned long long num);
int			ft_handle_d(t_format *s_format, int num);
int			ft_handle_u(t_format *s_format, unsigned int num);
int			ft_handle_x(t_format *s_format, unsigned int num, char x);

// get next line
typedef struct s_fd_list
{
	int					fd;
	char				*str;
	struct s_fd_list	*next;
}	t_fd_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);

#endif
