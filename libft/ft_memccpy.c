/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:04:59 by wipariso          #+#    #+#             */
/*   Updated: 2015/12/08 18:24:19 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t num)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)src;
	while (*ptr != (unsigned char)c && *ptr && num--)
		*(char*)dst++ = *ptr++;
	if (*ptr == (unsigned char)c)
	{
		*(char*)dst++ = *ptr;
		return (dst);
	}
	return (NULL);
}
