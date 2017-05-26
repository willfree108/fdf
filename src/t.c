/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:06:06 by wipariso          #+#    #+#             */
/*   Updated: 2016/06/29 15:09:34 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	tx(t_vertex *v, t_env *e)
{
	v->x += e->tx;
}

void	ty(t_vertex *v, t_env *e)
{
	v->y += e->ty;
}

void	tz(t_vertex *v, t_env *e)
{
	if (e->tz % 2 == 1)
		v->z *= -1;
}
