/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:34:16 by wipariso          #+#    #+#             */
/*   Updated: 2015/12/14 15:31:10 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_nblen(int n)
{
	int		cpt;

	cpt = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		cpt++;
	}
	return (cpt);
}

static int			ft_pow(int c, int n)
{
	int		tmp;

	tmp = c;
	n--;
	if (n == 0)
		return (1);
	while (--n)
		c *= tmp;
	return (c);
}

char				*ft_itoa(int n)
{
	int		len;
	int		sig;
	char	*head;
	char	*ptr;

	sig = 1;
	len = ft_nblen(n);
	if (n < 0)
	{
		if (!(ptr = ft_strnew(len + 1)))
			return (NULL);
		sig = -1;
		*ptr++ = '-';
	}
	else
	{
		if (!(ptr = ft_strnew(len)))
			return (NULL);
	}
	head = ptr;
	while (len)
		*ptr++ = (n / ft_pow(10, len--) % 10) * sig + '0';
	*ptr = 0;
	return (n < 0 ? head - 1 : head);
}
