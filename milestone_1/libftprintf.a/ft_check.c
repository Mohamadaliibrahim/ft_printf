/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:54:08 by mohamibr          #+#    #+#             */
/*   Updated: 2024/06/18 14:37:04 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.h"

void	pointer_p(char *str, void *p)
{
	unsigned long	x;
	int				i;
	int				j;
	const char		*hexa_digits;
	char			buffer[17];

	x = (unsigned long)p;
	i = 0;
	hexa_digits = "0123456789abcdef";
	if (x == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	while (x > 0)
	{
		buffer[i++] = hexa_digits[x % 16];
		x /= 16;
	}
	j = i - 1;
	while (j >= 0)
		str[i - 1 - j--] = buffer[j];
	str[i] = '\0';
}

void	hexa_u(char *str, unsigned int x)
{
	int			i;
	int			j;
	const char	*hexa_digit;
	char		buffer[9];

	i = 0;
	hexa_digit = "0123456789ABCDEF";
	if (x == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}	
	while (x > 0)
	{
		buffer[i++] = hexa_digit[x % 16];
		x /= 16;
	}
	j = i - 1;
	while (j >= 0)
		str[i - 1 - j--] = buffer[j];
	str[i] = '\0';
}

void	hexa(char *str, unsigned long x, char z)
{
	if (z == 'x')
		hexa_l(str, (unsigned int)x);
	else if (z == 'X')
		hexa_u(str, (unsigned int)x);
}

void	hexa_l(char *str, unsigned int x)
{
	int			i;
	int			j;
	const char	*hexa_digits;
	char		buffer[9];

	i = 0;
	hexa_digits = "0123456789abcdef";
	if (x == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	while (x > 0)
	{
		buffer[i++] = hexa_digits[x % 16];
		x /= 16;
	}
	j = i - 1;
	while (j >= 0)
		str[i - 1 - j--] = buffer[j];
	str[i] = '\0';
}

void	check_arg(const char ch, va_list ap)
{
	char	buffer[9];

	if (ch == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (ch == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (ch == 'i' || ch == 'd')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (ch == 'u')
		ft_putnbr_fd(va_arg(ap, unsigned int), 1);
	else if (ch == 'x' || ch == 'X')
	{
		hexa(buffer, va_arg(ap, unsigned int), ch);
		ft_putstr_fd(buffer, 1);
	}
	else if (ch == 'p')
	{
		pointer_p(buffer, va_arg(ap, void *));
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(buffer, 1);
	}
}
