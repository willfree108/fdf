/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 17:05:31 by wipariso          #+#    #+#             */
/*   Updated: 2016/06/29 15:09:15 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_init(t_env *e)
{
	e->min = 0;
	e->max = 0;
	e->m = 0;
	e->n = 0;
	e->rotx = 0;
	e->roty = 0;
	e->rotz = 0;
	e->tx = HEIGHT / 4;
	e->ty = WIDTH / 4;
	e->tz = 0;
	e->zmax = 0;
	e->scale = 1;
	e->c1 = 0;
	e->c2 = 0;
	e->c3 = 0;
	e->c4 = 0;
	e->force = 0;
}

static int		ft_fdf(int ac, char **av)
{
	t_env	e;

	fdf_init(&e);
	if (!(e.v = get(ac, av, &e)))
		return (1);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "fdf");
	mlx_hook(e.win, 2, 3, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}

int				main(int argc, char **argv)
{
	if (argc == 2 || argc == 6 || argc == 3 || argc == 7)
		ft_fdf(argc, argv);
	else
		ft_putstr("usage: fdf map.fdf");
	return (0);
}
