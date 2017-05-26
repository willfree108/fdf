/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 15:06:16 by wipariso          #+#    #+#             */
/*   Updated: 2016/06/29 15:09:25 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	rotz(t_vertex *v, t_env *e)
{
	float m;
	float n;
	float cs;
	float sn;

	m = v->x - e->m / 2;
	n = v->y - e->n / 2;
	cs = cos(e->rotz);
	sn = sin(e->rotz);
	v->x = m * cs - n * sn + e->m / 2;
	v->y = n * cs + m * sn + e->n / 2;
}

void	rotx(t_vertex *v, t_env *e)
{
	float n;
	float p;
	float cs;
	float sn;

	n = v->y - e->n / 2;
	p = v->z - e->zmax / 2;
	cs = cos(e->rotx);
	sn = sin(e->rotx);
	v->y = n * cs - p * sn + e->n / 2;
	v->z = p * cs + n * sn + e->zmax / 2;
}

void	roty(t_vertex *v, t_env *e)
{
	float m;
	float p;
	float cs;
	float sn;

	m = v->x - e->m / 2;
	p = v->z - e->zmax / 2;
	cs = cos(e->roty);
	sn = sin(e->roty);
	v->x = m * cs - p * sn + e->m / 2;
	v->z = p * cs + m * sn + e->zmax / 2;
}
