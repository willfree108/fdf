/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:54:00 by wipariso          #+#    #+#             */
/*   Updated: 2015/12/09 20:54:49 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_noprint(char c)
{
	if (c >= 0 && c <= 32)
		return (1);
	return (0);
}

int				ft_atoi(const char *nptr)
{
	int nb;
	int sig;

	nb = 0;
	sig = 1;
	while (ft_noprint(*nptr))
		nptr++;
	if (nptr[0] == '-')
		sig = -1;
	if (nptr[0] == '-' || nptr[0] == '+')
		nptr++;
	while (*nptr)
	{
		nb *= 10;
		if (!ft_isdigit(*nptr) && !nb)
			return (0);
		if (!ft_isdigit(*nptr) && nb)
			return (sig * nb / 10);
		nb += *nptr++ - '0';
	}
	return (sig * nb);
}
