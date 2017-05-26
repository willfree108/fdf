/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 17:06:40 by wipariso          #+#    #+#             */
/*   Updated: 2016/06/29 15:07:20 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	init(t_vertex *v, t_env *e)
{
	v->x = v->m;
	v->y = v->n;
	v->z = v->p;
}

static void	screen(t_vertex *v, t_env *e)
{
	v->x = v->x / (e->max + e->zmax) * (float)(HEIGHT / 2);
	if (e->m + e->n == 0)
		v->y = 0;
	else
		v->y = v->y / (float)(e->n) * (WIDTH / 2);
}

static void	scale(t_vertex *v, t_env *e)
{
	v->x *= e->scale;
	v->y *= e->scale;
	v->z *= e->scale;
}

static void	projection(t_vertex *v, t_env *e)
{
	v->x = v->x - v->z + e->zmax;
}

void		calc(t_vertex *v, t_env *e)
{
	init(v, e);
	tz(v, e);
	rotx(v, e);
	roty(v, e);
	rotz(v, e);
	projection(v, e);
	screen(v, e);
	scale(v, e);
	tx(v, e);
	ty(v, e);
}
