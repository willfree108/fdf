/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wipariso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 17:58:01 by wipariso          #+#    #+#             */
/*   Updated: 2016/06/29 15:03:17 by wipariso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1280
# define HEIGHT 1024
# define SGN(x) (( x < 0) ? -1 : ((x > 0)? 1 : 0))

# include "../libx/mlx.h"
# include "../libft/libft.h"

typedef struct			s_bre
{
	int					dx;
	int					dy;
	int					sdx;
	int					sdy;
	int					dxabs;
	int					dyabs;
	int					x;
	int					y;
	int					px;
	int					py;
}						t_bre;

typedef	struct			s_vertex
{
	int					m;
	int					n;
	int					p;
	float				x;
	float				y;
	float				z;
	int					color;
	struct s_vertex		*down;
	struct s_vertex		*next;
}						t_vertex;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	int					bits;
	int					endian;
	char				*data;
	int					sl;

	float				min;
	float				max;

	int					m;
	int					n;

	float				rotx;
	float				roty;
	float				rotz;

	int					tx;
	int					ty;
	int					tz;

	float				scale;

	float				zmax;
	int					c1;
	int					c2;
	int					c3;
	int					c4;
	int					force;
	t_vertex			*v;
	t_vertex			*head;
}						t_env;

t_vertex				*get(int ac, char **av, t_env *e);
t_vertex				*fill(char *path);
void					calc(t_vertex *v, t_env *e);
void					draw(t_env *e);
int						valid(int m, int n);

void					tx(t_vertex *v, t_env *e);
void					ty(t_vertex *v, t_env *e);
void					tz(t_vertex *v, t_env *e);

void					rotx(t_vertex *v, t_env *e);
void					roty(t_vertex *v, t_env *e);
void					rotz(t_vertex *v, t_env *e);

void					iter_v(t_vertex *v, t_env *e,
							void (f)(t_vertex *v, t_env *e));
void					add_v(t_vertex **v, char *str, int m, int n);

void					ft_tabiter(char **word, void (f)(char**));
int						ft_strtol(char *str);

int						expose_hook(t_env *e);
int						mouse_hook(int button, int x, int y, t_env *e);
int						key_hook(int keycode, t_env *e);

#endif
