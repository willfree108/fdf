/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 17:03:48 by wipariso          #+#    #+#             */
/*   Updated: 2016/06/29 15:08:59 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iter_v(t_vertex *v, t_env *e, void (f)(t_vertex *v, t_env *e))
{
	int			min;
	t_vertex	*tmp;

	while (v)
	{
		tmp = v;
		while (tmp)
		{
			f(tmp, e);
			tmp = tmp->next;
		}
		v = v->down;
	}
}
