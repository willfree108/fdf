/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 17:02:55 by wipariso          #+#    #+#             */
/*   Updated: 2016/06/29 15:08:47 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int			expose_hook(t_env *e)
{
	e->v = e->head;
	iter_v(e->v, e, &calc);
	draw(e);
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *e)
{
	return (0);
}

static int	key_hook_next(int keycode, t_env *e)
{
	if (keycode == 123)
		e->ty -= 10;
	if (keycode == 124)
		e->ty += 10;
	if (keycode == 76)
		e->tz += 1;
	if (keycode == 65)
	{
		e->rotx = 0;
		e->roty = 0;
		e->rotz = 0.80;
	}
	if (keycode == 82)
	{
		e->rotx = 0;
		e->roty = 0;
		e->rotz = 0;
	}
	e->v = e->head;
	mlx_destroy_image(e->mlx, e->img);
	iter_v(e->v, e, &calc);
	draw(e);
	return (0);
}

int			key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
		e->scale += 0.1;
	if (keycode == 78)
		e->scale -= 0.1;
	if (keycode == 89)
		e->rotx += 0.1;
	if (keycode == 91)
		e->rotx -= 0.1;
	if (keycode == 86)
		e->roty += 0.1;
	if (keycode == 87)
		e->roty -= 0.1;
	if (keycode == 83)
		e->rotz += 0.1;
	if (keycode == 84)
		e->rotz -= 0.1;
	if (keycode == 126)
		e->tx -= 10;
	if (keycode == 125)
		e->tx += 10;
	key_hook_next(keycode, e);
	return (0);
}
