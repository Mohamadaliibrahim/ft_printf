/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:44:09 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/27 15:07:05 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_countwords(const char *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s != c)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (words);
}

char	**ft_split(const char *s, char c)
{
	char	**words;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	words = malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!words)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			words[i++] = ft_substr(s - len, 0, len);
		}
		else
			s++;
	}
	words[i] = NULL;
	return (words);
}
