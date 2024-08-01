#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	count_words(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	inside_word = false;
	while (*s)
	{
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
		inside_word = false;
	}
	return (count);
}

static char	*get_next_word(char *s, char c, int *cursor)
{
	char	*next_word;
	int		len;
	int		i;

	len = 0;
	while (s[*cursor] == c)
		++(*cursor);
	while ((s[*cursor + len] != c) && s[*cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	i = 0;
	while ((s[*cursor] != c) && s[*cursor])
		next_word[i++] = s[(*cursor)++];
	next_word[i] = '\0';
	return (next_word);
}

char	**free_result_array(char **result_array, int i)
{
	while (i-- > 0)
		free(result_array[i]);
	free(result_array);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	int		words_count;
	char	**result_array;
	int		i;
	int		cursor;

	words_count = count_words(s, c);
	if (!words_count)
		exit(1);
	result_array = malloc(sizeof(char *) * (words_count + 1));
	if (!result_array)
		return (NULL);
	i = 0;
	cursor = 0;
	while (words_count-- >= 0)
	{
		if (i == 0)
			result_array[i] = ft_strdup("");
		else
			result_array[i] = get_next_word(s, c, &cursor);
		if (!result_array[i])
			return (free_result_array(result_array, i));
		i++;
	}
	result_array[i] = NULL;
	return (result_array);
}
