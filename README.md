## Welcome to FDF

A 42 project in C with a tiny graphic lib (miniLibX), beginning of the track infography.
Wireframe (literraly) a map.

It's also done under the 42 norm:
  - a function musn't exceed 25 lines.
  - a file can't exceed 5 functions.
  - a lot of lib are forbidden
  - a lot of things like that ...
  
# GIF

![](https://media.giphy.com/media/3og0IAQCwWzrihcBbi/giphy.gif)
[If it doesn't load, please click here](https://media.giphy.com/media/3og0IAQCwWzrihcBbi/giphy.gif)
# Interesting parts

```
// on src/calc.c
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

// on src/draw.c
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
```

Have a nice day.
