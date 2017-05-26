/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:16:06 by wipariso          #+#    #+#             */
/*   Updated: 2015/12/11 15:33:58 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *c, char (*f)(unsigned int, char))
{
	unsigned int	cpt;
	char			*ptr;
	char			*head;

	cpt = 0;
	if (!(ptr = (char*)ft_memalloc(ft_strlen(c) + 1)))
		return (NULL);
	head = ptr;
	while (c[cpt])
	{
		*ptr = f(cpt, c[cpt]);
		ptr++;
		cpt++;
	}
	*ptr = 0;
	return (head);
}
