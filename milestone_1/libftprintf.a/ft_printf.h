/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:08:59 by mohamibr          #+#    #+#             */
/*   Updated: 2024/06/18 12:12:04 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <unistd.h>

int     ft_printf(const char *hello, ...);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	check_arg(const char ch, va_list ap);
void	hexa_l(char *str, unsigned int x);
void	hexa(char *str, unsigned long x, int z);
void	hexa_u(char *str, unsigned int x);
void	pointer_p(char *str, void *p);

#endif
