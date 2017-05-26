/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:15:25 by wipariso          #+#    #+#             */
/*   Updated: 2015/12/08 20:15:22 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	char	tmp;
	char	*head;
	size_t	cpt;

	head = dst;
	cpt = num - 1;
	if (src < dst)
		while (num--)
		{
			tmp = ((char*)src)[cpt];
			((char*)dst)[cpt--] = tmp;
		}
	else
		while (num--)
			*(char*)dst++ = *(char*)src++;
	return (head);
}
