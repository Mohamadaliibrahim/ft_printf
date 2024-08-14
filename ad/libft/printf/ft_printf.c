/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:03:00 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/27 15:40:09 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_value(va_list args, t_format *s_format, int *len)
{
	char	c;

	c = s_format->specifier;
	if (c == 'c')
		*len += ft_handle_c(s_format, (char)va_arg(args, int));
	else if (c == 's')
		*len += ft_handle_s(s_format, va_arg(args, char *));
	else if (c == 'x' || c == 'X')
		*len += ft_handle_x(s_format, va_arg(args, unsigned int), c);
	else if (c == 'p')
		*len += ft_handle_p(s_format, va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		*len += ft_handle_d(s_format, va_arg(args, int));
	else if (c == 'u')
		*len += ft_handle_u(s_format, va_arg(args, unsigned int));
	return ;
}

t_format	ft_format(char **ptr)
{
	t_format	s_format;

	s_format.flags = parse_flags(ptr);
	s_format.width = parse_width(ptr);
	s_format.precision = parse_precision(ptr);
	s_format.specifier = parse_specifier(ptr);
	return (s_format);
}

int	ft_printf(const char *format, ...)
{
	int			len;
	char		*ptr;
	va_list		args;
	t_format	s_format;

	va_start(args, format);
	ptr = (char *)format;
	len = 0;
	while (*ptr)
	{
		if (*ptr == '%' && *(++ptr) && *ptr != '%')
		{
			s_format = ft_format(&ptr);
			ft_value(args, &s_format, &len);
			free(s_format.flags);
		}
		else
			len += ft_putchar_fd(*ptr, 1);
		ptr++;
	}
	va_end(args);
	return (len);
}
