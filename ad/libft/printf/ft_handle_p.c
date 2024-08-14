/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:26:51 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/17 14:26:51 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_ptrlen(unsigned long long num)
{
	int					len;
	unsigned long long	temp;

	len = 0;
	temp = num;
	if (!num)
		return (5);
	if (temp == 0)
		return (1);
	while (temp != 0)
	{
		temp /= 16;
		len++;
	}
	return (len + 2);
}

int	ft_handle_p(t_format *s_format, unsigned long long num)
{
	int	len;
	int	nbrlen;
	int	isplus;
	int	isminus;

	isplus = ft_in('+', s_format->flags);
	isminus = ft_in('-', s_format->flags);
	len = 0;
	nbrlen = ft_ptrlen(num);
	if (isplus)
		nbrlen++;
	if (s_format->width < nbrlen)
		s_format->width = nbrlen;
	if (!isminus)
		while (s_format->width-- > nbrlen)
			len += ft_putchar_fd(' ', 1);
	if (isplus)
		len += ft_putchar_fd('+', 1);
	len += ft_putptr_fd(num, 1);
	if (isminus)
		while (s_format->width-- > nbrlen)
			len += ft_putchar_fd(' ', 1);
	return (len);
}
