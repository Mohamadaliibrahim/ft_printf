/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:38:37 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/27 15:44:02 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_ulen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_before(t_format *s, int ulen, unsigned int nb, int isminus)
{
	int	len;
	int	isplus;
	int	iszero;

	isplus = ft_in('+', s->flags);
	iszero = ft_in('0', s->flags);
	len = 0;
	if (isplus)
		ulen++;
	if (s->width < ulen)
		s->width = ulen;
	if (!isminus && (!iszero || s->precision >= 0))
		while (--s->width - s->precision > ulen)
			len += ft_putchar_fd(' ', 1);
	if (isplus)
		len += ft_putchar_fd('+', 1);
	if (iszero && !isminus)
		while (s->precision < 0 && s->width-- > ulen)
			len += ft_putchar_fd('0', 1);
	while (s->precision-- > ft_ulen(nb))
		len += ft_putchar_fd('0', 1);
	return (len);
}

int	ft_handle_u(t_format *s_format, unsigned int nb)
{
	int	len;
	int	ulen;
	int	isminus;

	isminus = ft_in('-', s_format->flags);
	len = 0;
	ulen = ft_ulen(nb);
	len += ft_before(s_format, ulen, nb, isminus);
	len += ft_putunbr_fd(nb, 1);
	if (isminus)
		while (s_format->width-- > ulen)
			len += ft_putchar_fd(' ', 1);
	return (len);
}
