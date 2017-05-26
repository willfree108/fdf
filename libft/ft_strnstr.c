/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:03:03 by wipariso          #+#    #+#             */
/*   Updated: 2015/12/14 15:04:56 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	ft_strnncmp(const char *s1, const char *s2, size_t len, size_t n)
{
	while (*(unsigned char*)s1 == *(unsigned char*)s2
			&& *s1 && *s2 && n && len)
	{
		len--;
		s2++;
		s1++;
		n--;
	}
	if (!n)
		return (0);
	if (!len)
		return (1);
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (NULL);
	if (*s2 == 0)
		return ((char*)s1);
	while (n && *s1)
	{
		if (ft_strnncmp(s1, s2, n, ft_strlen(s2)) == 0 && n)
			return ((char*)s1);
		s1++;
		n--;
	}
	return (NULL);
}
