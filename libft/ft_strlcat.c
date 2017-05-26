/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 13:31:04 by wipariso          #+#    #+#             */
/*   Updated: 2015/12/11 14:47:38 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	const size_t	len_dest = ft_strlen(dest);
	const size_t	len_src = ft_strlen(src);
	size_t			n;

	n = size - len_dest;
	if (size < len_dest)
		return (size + len_src);
	dest = dest + len_dest;
	while (n-- > 1)
		*dest++ = *src++;
	*dest = 0;
	return (len_dest + len_src);
}
