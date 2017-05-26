/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:16:35 by wipariso          #+#    #+#             */
/*   Updated: 2015/12/11 15:33:46 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *c, char (*f)(char))
{
	char	*ptr;
	char	*head;

	if (!(ptr = (char*)ft_memalloc(ft_strlen(c) + 1)))
		return (NULL);
	head = ptr;
	while (*c)
	{
		*ptr = f(*c);
		ptr++;
		c++;
	}
	*ptr = 0;
	return (head);
}
