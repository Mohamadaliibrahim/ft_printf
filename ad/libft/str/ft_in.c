/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:49:37 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/27 15:49:37 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_in(const char s, const char *set)
{
	int	times;

	times = 0;
	while (*set)
	{
		if (s == *set)
			times++;
		set++;
	}
	return (times);
}
