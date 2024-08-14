/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:47:11 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/27 15:48:56 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		start;
	size_t		end;

	end = ft_strlen(s1);
	start = 0;
	while (ft_in(s1[start], set))
		start++;
	while (ft_in(s1[end - 1], set) && end > start)
		end--;
	str = malloc(sizeof(char) * ((end - start) + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, (end - start) + 1);
	return (str);
}
