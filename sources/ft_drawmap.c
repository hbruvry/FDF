/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 09:07:53 by hbruvry           #+#    #+#             */
/*   Updated: 2018/02/28 10:54:18 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_rgb	ft_rgb(int hex)
{
	t_rgb	c;

	c.r = ((hex >> 16) & 0xFF);
	c.g = ((hex >> 8) & 0xFF);
	c.b = (hex & 0xFF);
	return (c);
}

/*
** printf("i = %d, j = %d, c.ca = %d, c.cb = %d\n", i, j, c.ca, c.cb);
*/

int		ft_mapcol(int d, t_env *e)
{
	t_inc	i;
	t_rgb	ca;
	t_rgb	cb;
	t_rgb	cc;
	t_rgb	cd;

	i.i = e->zmax;
	ca = ft_rgb(e->ca);
	cb = ft_rgb(e->cb);
	cc = ft_rgb(e->cc);
	if (d < 0)
	{
		i.i = e->zmin;
		ca = cc;
	}
	cd.r = (cb.r - ca.r) / i.i;
	cd.g = (cb.g - ca.g) / i.i;
	cd.b = (cb.b - ca.b) / i.i;
	i.j = e->cb + ((int)(cd.r * d) * 0x10000) + ((int)(cd.g * d) * 0x100)
	+ (int)(cd.b * d);
	i.j = (d == e->zmax) ? e->cc : i.j;
	i.j = (d == e->zmin) ? e->ca : i.j;
	return (i.j);
}

t_col	ft_col(int i, int j)
{
	t_col	c;
	t_env	*e;

	e = ft_getenv();
	c.ca = ft_mapcol(i, e);
	c.cb = ft_mapcol(j, e);
	return (c);
}

void	ft_drawiso(t_inc i, t_ctrl c)
{
	t_pos	p;
	t_env	*e;

	e = ft_getenv();
	p.xa = i.k + (i.j - i.i) * (2 * c.s);
	p.ya = i.l + (i.j + i.i) * c.s * (cos(c.r) - sin(c.r))
		- e->map[i.i][i.j] * c.d * (cos(c.r) + sin(c.r));
	if (i.j + 1 < e->x)
	{
		p.xb = i.k + (i.j + 1 - i.i) * (2 * c.s);
		p.yb = i.l + (i.j + i.i + 1) * c.s * (cos(c.r) - sin(c.r))
			- e->map[i.i][i.j + 1] * c.d * (cos(c.r) + sin(c.r));
		ft_drawline(p, ft_col(e->map[i.i][i.j], e->map[i.i][i.j + 1]));
	}
	if (i.i + 1 < e->y)
	{
		p.xb = i.k + ((i.j + 1 - i.i) * (2 * c.s) - (4 * c.s));
		p.yb = i.l + (i.j + i.i + 1) * c.s * (cos(c.r) - sin(c.r))
			- e->map[i.i + 1][i.j] * c.d * (sin(c.r) + cos(c.r));
		ft_drawline(p, ft_col(e->map[i.i][i.j], e->map[i.i + 1][i.j]));
	}
	return ;
}

void	ft_drawmap(void)
{
	t_ctrl	c;
	t_inc	i;
	t_env	*e;

	i.i = -1;
	i.j = -1;
	e = ft_getenv();
	c.s = e->s / 10 * e->mw;
	c.d = e->d / 10 * c.s / 10;
	c.r = e->r;
	i.k = WIDTH / 2 - c.s * (e->x + e->y) + (c.s * 2 * e->y) + e->mx;
	i.l = HEIGHT / 2 - c.s * ((e->x + e->y) / 2 - 1) + e->my;
	while (++i.i < e->y)
	{
		while (++i.j < e->x)
			ft_drawiso(i, c);
		i.j = -1;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->pic, 0, 0);
	return ;
}
