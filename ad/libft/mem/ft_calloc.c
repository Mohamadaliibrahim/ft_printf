/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajabado <ajabado@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:47:43 by ajabado           #+#    #+#             */
/*   Updated: 2024/06/26 16:18:47 by ajabado          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if (num && size > ((size_t)-1) / num)
		return (NULL);
	ptr = malloc(num * size);
	if (ptr)
		ft_memset(ptr, 0, num * size);
	return (ptr);
}
