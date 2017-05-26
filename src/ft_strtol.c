/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:56:40 by wipariso          #+#    #+#             */
/*   Updated: 2016/06/29 15:08:12 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

int	ft_strtol(char *str)
{
	int i;
	int res;
	int len;

	i = 0;
	res = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			res += (str[i] - '0') * pow(16, len - i - 1);
		else
			res += (str[i] - 'A' + 10) * pow(16, len - i - 1);
		i++;
	}
	return (res);
}
