/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:46:21 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/27 15:07:05 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *str, const char *c, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!c[0])
		return ((char *)str);
	while (i < len && str[i])
	{
		j = 0;
		while (i + j < len && str[i + j] == c[j] && str[i + j] && c[j])
		{
			if (!(c[j + 1]))
				return ((char *)(str + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
