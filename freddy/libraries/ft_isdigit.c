/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:27:34 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/08 17:32:32 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(unsigned char get_chars)
{
	if (get_chars >= '0' && get_chars <= '9')
		return (1);
	return (0);
}
