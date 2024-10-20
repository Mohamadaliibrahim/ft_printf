/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <mohamibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:06:16 by mohamibr          #+#    #+#             */
/*   Updated: 2024/10/20 15:06:35 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_printf(const char *hello, ...)
{
	va_list		ap;
	int			count;

	count = 0;
	va_start(ap, hello);
	while (*hello)
	{
		if (*hello == '%' && *(++hello) && *hello != '\0')
		{
			if (*hello == '%')
				count += ft_putchar_fd('%', 1);
			else
				check_arg(*hello, ap, &count);
		}
		else
		{
			ft_putchar_fd(*hello, 1);
			count++;
		}
		hello++;
	}
	va_end(ap);
	return (count);
}
