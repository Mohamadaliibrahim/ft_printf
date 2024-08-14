/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:38:26 by ajabado           #+#    #+#             */
/*   Updated: 2024/07/29 21:38:26 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_puthex_fd(unsigned int num, int fd, char format)
{
	char	*hex_digits;
	char	buffer[20];
	int		i;
	int		len;

	len = 0;
	i = 0;
	hex_digits = "0123456789abcdef";
	if (format == 'X')
		hex_digits = "0123456789ABCDEF";
	if (num == 0)
		return (ft_putchar_fd('0', fd));
	while (num)
	{
		buffer[i++] = hex_digits[num % 16];
		num /= 16;
	}
	while (i > 0)
		len += ft_putchar_fd(buffer[--i], fd);
	return (len);
}
