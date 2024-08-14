/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:20:01 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/17 14:20:01 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_handle_c(t_format *s_format, const char c)
{
	int	len;
	int	isminus;

	isminus = ft_in('-', s_format->flags);
	len = 0;
	if (s_format->width < 1)
		s_format->width = 1;
	if (!isminus)
		while (s_format->width-- > 1)
			len += ft_putchar_fd(' ', 1);
	if (s_format->precision < 0 || s_format->precision > 1)
		s_format->precision = 1;
	len += ft_putchar_fd(c, 1);
	if (isminus)
		while (s_format->width-- > 1)
			len += ft_putchar_fd(' ', 1);
	return (len);
}
