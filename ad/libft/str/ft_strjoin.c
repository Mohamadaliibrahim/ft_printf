/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:19:31 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/27 14:19:56 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		res_len;
	char	*res;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1) + 1;
	res_len = s1_len + ft_strlen(s2);
	res = ft_calloc(res_len, sizeof(char));
	if (!res)
		return (0);
	ft_strlcat(res, s1, s1_len);
	ft_strlcat(res, s2, res_len);
	return (res);
}
