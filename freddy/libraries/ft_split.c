/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:42:14 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/08 17:32:11 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	size_t	ft_wordcount(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

int	ft_failure(char **tab, int i)
{
	if (!tab[i])
	{
		while (i > 0)
			free(tab[--i]);
		free(tab);
		return (1);
	}
	return (0);
}

int	sign_duplication(const char *s, int n)
{
	int	flag;

	flag = 0;
	if (n == 1 && (s[n - 1] == '-' || s[n - 1] == '+'))
		return (1);
	while (n >= 0)
	{
		if ((s[n] == '-' || s[n] == '+') && n != 0)
			flag = 1;
		else if (flag)
			return (1);
		n--;
	}
	return (0);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*copy;
	size_t	i;

	if (sign_duplication(s, n))
		return (NULL);
	copy = malloc(n + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < n && *s != '\0')
	{
		if (ft_isdigit(*s) || (*s == '-' || *s == '+'))
		{
			copy[i] = *s;
			i++;
			s++;
		}
		else
		{
			free(copy);
			return (NULL);
		}
	}
	copy[i] = '\0';
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	const char	*word_start;
	char		**tab;
	size_t		i;

	tab = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!s || !tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			word_start = s;
			while (*s && *s != c)
				s++;
			tab[i] = ft_strndup(word_start, s - word_start);
			if (ft_failure(tab, i))
				return (NULL);
			i++;
		}
		else
			s++;
	}
	tab[i] = NULL;
	return (tab);
}
