/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:16:49 by wipariso          #+#    #+#             */
/*   Updated: 2015/12/03 16:21:35 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *data, int value, size_t len)
{
	char *ptr;

	ptr = data;
	while (len--)
		*ptr++ = (unsigned char)value;
	return (data);
}
