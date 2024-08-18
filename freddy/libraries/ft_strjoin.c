/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:40:02 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/08 17:30:31 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*join;

	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!join || !s1 || !s2)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		join[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		join[i] = *s2;
		s2++;
		i++;
	}
	join[i] = ' ';
	join[i + 1] = '\0';
	return (join);
}
