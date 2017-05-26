/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:59:53 by wipariso          #+#    #+#             */
/*   Updated: 2016/06/29 15:08:38 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static void	get_limit(t_vertex *v, t_env *e)
{
	if (e->min > v->p)
		e->min = v->z;
	if (e->m < v->m)
		e->m = v->m;
	if (e->n < v->n)
		e->n = v->n;
}

static void	get_max(t_vertex *v, t_env *e)
{
	int tmp;

	if (e->zmax < v->p)
		e->zmax = v->p;
	tmp = abs(v->m - v->p);
	if (e->max < tmp)
		e->max = tmp;
}

static void	get_pos(t_vertex *v, t_env *e)
{
	v->z += abs(e->min);
}

static void	get_color(t_vertex *v, t_env *e)
{
	if (v->color == 0xFFFFFF || e->force)
	{
		if (v->p < e->zmax / 4)
			v->color = e->c1 ? e->c1 : 0x0000FF;
		else if (v->p < e->zmax / 2)
			v->color = e->c2 ? e->c2 : 0x00FF00;
		else if (v->p < e->zmax / 1.3)
			v->color = e->c3 ? e->c3 : 0xFF4500;
		else
			v->color = e->c4 ? e->c4 : 0xFFFFFF;
	}
}

t_vertex	*get(int ac, char **av, t_env *e)
{
	t_vertex *v;

	if (!(v = fill(av[1])))
		return (NULL);
	e->n = 0;
	iter_v(v, e, &get_limit);
	if (e->min < 0)
		iter_v(v, e, &get_pos);
	iter_v(v, e, &get_max);
	if (ac >= 3 && av[2][0] == 'f')
		e->force = 1;
	if (ac >= 3 && av[2][0] == 'b')
		e->force = 2;
	if ((ac == 6 && !e->force) || (ac == 7 && e->force) || e->force == 2)
	{
		e->c1 = e->force == 2 ? 0xFFFFFF : ft_strtol(av[2 + e->force]);
		e->c2 = e->force == 2 ? 0xFFFFFF : ft_strtol(av[3 + e->force]);
		e->c3 = e->force == 2 ? 0xFFFFFF : ft_strtol(av[4 + e->force]);
		e->c4 = e->force == 2 ? 0xFFFFFF : ft_strtol(av[5 + e->force]);
	}
	iter_v(v, e, &get_color);
	e->head = v;
	return (v);
}
