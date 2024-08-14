/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 02:39:04 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/17 02:39:04 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*parse_flags(char **ptr)
{
	char	*flags;
	int		i;

	i = 0;
	flags = malloc(sizeof(char) * 7);
	ft_memset(flags, 0, 7);
	while (ft_in(**ptr, "-+ 0#"))
	{
		if (!ft_in(**ptr, flags))
			flags[i++] = **ptr;
		(*ptr)++;
	}
	flags[i] = '\0';
	return (flags);
}

int	parse_width(char **ptr)
{
	int	width;

	width = 0;
	if (ft_isdigit(**ptr))
	{
		width = atoi(*ptr);
		while (ft_isdigit(**ptr))
			(*ptr)++;
	}
	return (width);
}

int	parse_precision(char **ptr)
{
	int	precision;

	precision = -1;
	if (**ptr == '.')
	{
		(*ptr)++;
		precision = atoi(*ptr);
		while (ft_isdigit(**ptr))
			(*ptr)++;
	}
	return (precision);
}

char	parse_specifier(char **ptr)
{
	if (ft_in(**ptr, "cspdiuxX"))
		return (**ptr);
	return ('\0');
}
