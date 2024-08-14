/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:05:24 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/17 16:05:24 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_abs(int nb)
{
	if (nb >= 0)
		return (nb);
	else
		return (-nb);
}

static int	ft_before(t_format *s_format, int nbrlen, int nb, int isminus)
{
	int	len;
	int	isplus;
	int	iszero;

	isplus = ft_in('+', s_format->flags);
	iszero = ft_in('0', s_format->flags);
	len = 0;
	if (isplus && nb != -2147483648 && nb >= 0)
		nbrlen++;
	if (s_format->width < nbrlen)
		s_format->width = nbrlen;
	if (!isminus && (!iszero || s_format->precision >= 0))
		while (--s_format->width - s_format->precision > nbrlen)
			len += ft_putchar_fd(' ', 1);
	if (isplus && nb != -2147483648 && nb >= 0)
		len += ft_putchar_fd('+', 1);
	else if (nb < 0 && nb != -2147483648)
		len += ft_putchar_fd('-', 1);
	if (iszero && !isminus)
		while (s_format->precision < 0 && s_format->width-- > nbrlen)
			len += ft_putchar_fd('0', 1);
	while (s_format->precision-- > ft_nbrlen(ft_abs(nb)))
		len += ft_putchar_fd('0', 1);
	return (len);
}

int	ft_handle_d(t_format *s_format, int nb)
{
	int	len;
	int	nbrlen;
	int	isminus;
	int	isspace;

	isminus = ft_in('-', s_format->flags);
	isspace = ft_in(' ', s_format->flags);
	len = 0;
	nbrlen = ft_nbrlen(nb);
	len += ft_before(s_format, nbrlen, nb, isminus);
	if (isspace && s_format->width <= nbrlen && nb >= 0)
		len += ft_putchar_fd(' ', 1);
	len += ft_putnbr_fd(ft_abs(nb), 1);
	if (isminus)
		while (s_format->width-- > nbrlen)
			len += ft_putchar_fd(' ', 1);
	return (len);
}
