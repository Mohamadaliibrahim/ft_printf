/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 00:54:05 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/27 15:40:09 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_hexlen(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static int	ft_before(t_format *s, int xlen, unsigned int nb, int isminus)
{
	int	len;
	int	iszero;

	iszero = ft_in('0', s->flags);
	len = 0;
	if (s->width < xlen)
		s->width = xlen;
	if (!isminus && (!iszero || s->precision >= 0))
		while (--s->width - s->precision > xlen)
			len += ft_putchar_fd(' ', 1);
	if (iszero && !isminus)
		while (s->precision < 0 && s->width-- > xlen)
			len += ft_putchar_fd('0', 1);
	while (s->precision-- > ft_hexlen(nb))
		len += ft_putchar_fd('0', 1);
	return (len);
}

int	ft_handle_x(t_format *s_format, unsigned int nb, char x)
{
	int	len;
	int	xlen;
	int	isminus;
	int	ishashtag;

	isminus = ft_in('-', s_format->flags);
	ishashtag = ft_in('#', s_format->flags);
	len = 0;
	xlen = ft_hexlen(nb);
	len += ft_before(s_format, xlen, nb, isminus);
	if (ishashtag && nb)
	{
		len += ft_putchar_fd('0', 1);
		len += ft_putchar_fd(x, 1);
	}
	len += ft_puthex_fd(nb, 1, x);
	if (isminus)
		while (s_format->width-- > xlen)
			len += ft_putchar_fd(' ', 1);
	return (len);
}
