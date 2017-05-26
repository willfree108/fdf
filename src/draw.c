/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 17:54:27 by wipariso          #+#    #+#             */
/*   Updated: 2016/06/29 15:07:31 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <math.h>

static void	draw_dot(t_env *e, int m, int n, int color)
{
	int i;

	if (!valid(m, n))
		return ;
	i = m * e->sl + n * 4;
	e->data[i] = mlx_get_color_value(e->mlx, color);
	e->data[i + 1] = mlx_get_color_value(e->mlx, color) >> 8;
	e->data[i + 2] = mlx_get_color_value(e->mlx, color) >> 16;
}

static void	draw_line_yx(t_bre *bre, t_env *e, int color)
{
	int i;

	i = -1;
	while (++i < bre->dyabs)
	{
		bre->x += bre->dxabs;
		if (bre->x >= bre->dyabs)
		{
			bre->x -= bre->dyabs;
			bre->px += bre->sdx;
		}
		bre->py += bre->sdy;
		draw_dot(e, bre->px, bre->py, color);
	}
}

static void	draw_line_xy(t_bre *bre, t_env *e, int color)
{
	int i;

	i = -1;
	while (++i < bre->dxabs)
	{
		bre->y += bre->dyabs;
		if (bre->y >= bre->dxabs)
		{
			bre->y -= bre->dxabs;
			bre->py += bre->sdy;
		}
		bre->px += bre->sdx;
		draw_dot(e, bre->px, bre->py, color);
	}
}

static void	draw_line(t_env *e, t_vertex *v1, t_vertex *v2)
{
	t_bre bre;

	bre.dx = v2->x - v1->x;
	bre.dy = v2->y - v1->y;
	bre.dxabs = abs(bre.dx);
	bre.dyabs = abs(bre.dy);
	bre.sdx = SGN(bre.dx);
	bre.sdy = SGN(bre.dy);
	bre.x = bre.dyabs >> 1;
	bre.y = bre.dxabs >> 1;
	bre.px = v1->x;
	bre.py = v1->y;
	if (bre.dxabs >= bre.dyabs)
		draw_line_xy(&bre, e, v1->color);
	else
		draw_line_yx(&bre, e, v1->color);
}

void		draw(t_env *e)
{
	t_vertex *tmp;
	t_vertex *cur;

	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->bits = 24;
	e->endian = 1;
	e->sl = e->bits * e->n;
	e->data = mlx_get_data_addr(e->img, &e->bits, &e->sl, &e->endian);
	while (e->v)
	{
		tmp = e->v;
		e->v = e->v->down;
		cur = e->v;
		while (tmp)
		{
			draw_dot(e, tmp->x, tmp->y, tmp->color);
			tmp->next ? draw_line(e, tmp, tmp->next) : 0;
			cur ? draw_line(e, tmp, cur) : 0;
			tmp = tmp->next;
			if (cur && cur->next)
				cur = cur->next;
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
