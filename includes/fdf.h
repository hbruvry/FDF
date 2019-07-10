/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:29:34 by hbruvry           #+#    #+#             */
/*   Updated: 2018/06/12 11:59:52 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H

# include "libft/libft.h"
# include "/usr/local/include/mlx.h"
# include <math.h>
# include <fcntl.h>

# define BUFF_SIZE 4096
# define WIDTH 500
# define HEIGHT 500

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	void		*pic;
	int			*picstr;
	int			**map;
	int			a;
	int			b;
	int			c;
	int			x;
	int			y;
	int			zmax;
	int			zmin;
	int			mx;
	int			my;
	float		mw;
	int			ca;
	int			cb;
	int			cc;
	float		s;
	float		d;
	float		r;
	float		td;
	int			k;
}				t_env;

typedef	struct	s_col
{
	int			ca;
	int			cb;
}				t_col;

typedef	struct	s_rgb
{
	float	r;
	float	g;
	float	b;
}				t_rgb;

typedef	struct	s_inc
{
	int			i;
	int			j;
	int			k;
	int			l;
}				t_inc;

typedef	struct	s_ctrl
{
	float		s;
	float		d;
	float		r;
}				t_ctrl;

typedef	struct	s_rot
{
	float		x;
	float		y;
	float		z;
}				t_rot;

typedef	struct	s_pos
{
	int			xa;
	int			ya;
	int			ca;
	int			xb;
	int			yb;
	int			cb;
}				t_pos;

typedef	struct	s_line
{
	int			x;
	int			y;
	int			dx;
	int			dy;
	int			i;
	int			xi;
	int			yi;
	int			res;
}				t_line;

int				ft_setenv(char *file, t_env *e);
t_env			*ft_getenv(void);
void			ft_debug(void);
void			ft_drawline(t_pos p, t_col c);
t_rgb			ft_rgb(int hex);
void			ft_drawmap(void);
void			ft_drawtxt(void);
int				ft_mousehook(int key, int x, int y, t_env *e);
int				ft_keyhook(int key, t_env *e);

#endif
