/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_v.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:53:40 by wipariso          #+#    #+#             */
/*   Updated: 2016/06/29 14:56:04 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <unistd.h>
#include <stdlib.h>

void	add_v(t_vertex **v, char *str, int m, int n)
{
	if (!(*v))
	{
		if (!(*v = ft_memalloc(sizeof(t_vertex))))
			return ;
		(*v)->m = m;
		(*v)->n = n;
		(*v)->p = ft_atoi(str);
		if (ft_strchr(str, 'x'))
			(*v)->color = ft_strtol(ft_strchr(str, 'x') + 1);
		else
			(*v)->color = 0xFFFFFF;
		(*v)->next = NULL;
		(*v)->down = NULL;
	}
	else if ((*v)->m < m)
		add_v(&(*v)->down, str, m, n);
	else if ((*v)->n < n)
		add_v(&(*v)->next, str, m, n);
}
