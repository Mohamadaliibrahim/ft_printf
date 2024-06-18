/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:06:16 by mohamibr          #+#    #+#             */
/*   Updated: 2024/06/18 12:07:14 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *hello, ...)
{
	const char	*ch;
	va_list		arg;
	int	count;

	count = 0;
	ch = hello;
	va_start(arg, hello);
	while (*ch)
	{
		if (*ch == '%' && *(++ch) && (*ch) != '%')
		{
			check_arg(*ch, arg, &count);
		}
		else
		{
			ft_putchar_fd(*ch, 1);
			count++;
		}
		ch++;
	}
	va_end(arg);
	return (count);
}
