/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:38:53 by wipariso          #+#    #+#             */
/*   Updated: 2015/12/11 15:59:30 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pow(int c, int n)
{
	int	tmp;

	tmp = c;
	n--;
	if (n == 0)
		return (1);
	while (--n)
		c *= tmp;
	return (c);
}

static int	ft_nblen(int n)
{
	int	cpt;

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

void		ft_putnbr_fd(int n, int fd)
{
	int sig;
	int	len;

	sig = 1;
	len = ft_nblen(n);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		sig = -1;
	}
	while (len)
		ft_putchar_fd((n / ft_pow(10, len--) % 10) * sig + '0', fd);
}
