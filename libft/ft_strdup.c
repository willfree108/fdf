/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:55:07 by wipariso          #+#    #+#             */
/*   Updated: 2016/03/16 13:43:24 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*tmp;

	size = ft_strlen(s1) + 1;
	if (!(tmp = (char*)malloc(size)))
		return (NULL);
	tmp = malloc(size);
	ft_memcpy(tmp, s1, size);
	return (tmp);
}
