/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:58:50 by wipariso          #+#    #+#             */
/*   Updated: 2015/12/08 17:00:28 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	index;

	index = -1;
	while (++index < n && src[index])
		dest[index] = src[index];
	while (index < n)
		dest[index++] = 0;
	return (dest);
}
