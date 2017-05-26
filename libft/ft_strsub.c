/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:17:05 by wipariso          #+#    #+#             */
/*   Updated: 2015/12/09 19:13:41 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*head;
	char	*ptr;

	ptr = ft_strnew(len);
	if (!ptr)
		return (NULL);
	head = ptr;
	len += start;
	while (start < len)
	{
		*ptr++ = s[start];
		start++;
	}
	return (head);
}
