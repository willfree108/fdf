/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:56:45 by wipariso          #+#    #+#             */
/*   Updated: 2015/12/08 23:33:45 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n && *(unsigned char*)s != (unsigned char)c)
	{
		s++;
		n--;
	}
	if (!n)
		return (NULL);
	return ((void*)s);
}
