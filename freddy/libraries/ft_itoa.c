/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:24:19 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/12 00:20:45 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_len(int num)
{
	int				len;
	unsigned int	n;

	len = 0;
	if (num <= 0)
		len = 1;
	n = num;
	if (num < 0)
		n = -num;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*num;
	int				len;
	unsigned int	n_abs;

	len = ft_len(n);
	num = (char *)malloc((len + 1) * sizeof(char));
	if (!num)
		return (NULL);
	num[len] = '\0';
	if (n == 0)
		num[0] = '0';
	if (n < 0)
		n_abs = -n;
	else
		n_abs = n;
	while (n_abs > 0)
	{
		num[--len] = (n_abs % 10) + '0';
		n_abs /= 10;
	}
	if (n < 0)
		num[0] = '-';
	return (num);
}
