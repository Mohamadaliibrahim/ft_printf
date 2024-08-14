/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 03:40:43 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/17 03:40:43 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_handle_s(t_format *s_format, const char *str)
{
	int		len;
	int		strlen;
	char	*ptr;
	int		isminus;

	isminus = ft_in('-', s_format->flags);
	len = 0;
	if (!str)
		str = "(null)";
	ptr = (char *)str;
	strlen = ft_strlen(str);
	if (s_format->width < strlen)
		s_format->width = strlen;
	if (!isminus)
		while (s_format->width-- > strlen)
			len += ft_putchar_fd(' ', 1);
	if (s_format->precision < 0 || s_format->precision > strlen)
		s_format->precision = strlen;
	while (s_format->precision--)
		len += ft_putchar_fd(*(ptr++), 1);
	if (isminus)
		while (s_format->width-- > strlen)
			len += ft_putchar_fd(' ', 1);
	return (len);
}
