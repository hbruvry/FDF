/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 09:07:53 by hbruvry           #+#    #+#             */
/*   Updated: 2018/02/28 19:19:09 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

/*
** Convert hexadecimal colors to rgb colors
*/

t_rgb	ft_rgbis(int hex)
{
	t_rgb	c;

	c.r = ((hex >> 16) & 0xFF);
	c.g = ((hex >> 8) & 0xFF);
	c.b = (hex & 0xFF);
	return (c);
}

/*
** Increments x because the segment is rather "horizontal"
*/

void	ft_drawhorizontal(t_line l, t_col c)
{
	t_rgb	ca;
	t_rgb	cb;
	t_rgb	cc;
	t_env	*e;

	e = ft_getenv();
	ca = ft_rgbis(c.ca);
	cb = ft_rgbis(c.cb);
	cc.r = (cb.r - ca.r) / l.dx;
	cc.g = (cb.g - ca.g) / l.dx;
	cc.b = (cb.b - ca.b) / l.dx;
	l.res = l.dx / 2;
	while (l.i++ < l.dx)
	{
		l.x += l.xi;
		l.res += l.dy;
		if (l.res >= l.dx)
		{
			l.res -= l.dx;
			l.y += l.yi;
		}
		if (0 < l.x && l.x < WIDTH && 0 < l.y && l.y < HEIGHT)
			e->picstr[l.y * WIDTH + l.x] = c.ca + ((int)(cc.r * l.i)
			* 0x10000) + ((int)(cc.g * l.i) * 0x100) + (int)(cc.b * l.i);
	}
}

/*
** Increments y because the segment is rather "vertical"
*/

void	ft_drawvertical(t_line l, t_col c)
{
	t_rgb	ca;
	t_rgb	cb;
	t_rgb	cc;
	t_env	*e;

	e = ft_getenv();
	ca = ft_rgbis(c.ca);
	cb = ft_rgbis(c.cb);
	cc.r = (cb.r - ca.r) / l.dy;
	cc.g = (cb.g - ca.g) / l.dy;
	cc.b = (cb.b - ca.b) / l.dy;
	l.res = l.dy / 2;
	while (l.i++ < l.dy)
	{
		l.y += l.yi;
		l.res += l.dx;
		if (l.res >= l.dy)
		{
			l.res -= l.dy;
			l.x += l.xi;
		}
		if (0 < l.x && l.x < WIDTH && 0 < l.y && l.y < HEIGHT)
			e->picstr[l.y * WIDTH + l.x] = c.ca + ((int)(cc.r * l.i)
			* 0x10000) + ((int)(cc.g * l.i) * 0x100) + (int)(cc.b * l.i);
	}
}

/*
** Drawing a segment using the Bresenham algorithm
*/

void	ft_drawline(t_pos p, t_col c)
{
	t_line	l;
	t_env	*e;

	e = ft_getenv();
	l.x = p.xa;
	l.y = p.ya;
	l.dx = p.xb - p.xa;
	l.dy = p.yb - p.ya;
	l.i = 1;
	l.xi = (l.dx > 0) ? 1 : -1;
	l.yi = (l.dy > 0) ? 1 : -1;
	l.dx = abs(l.dx);
	l.dy = abs(l.dy);
	if (0 < l.x && l.x < WIDTH && 0 < l.y && l.y < HEIGHT)
		e->picstr[l.y * WIDTH + l.x] = c.cb;
	if (l.dx > l.dy)
		ft_drawhorizontal(l, c);
	else
		ft_drawvertical(l, c);
	if (0 < l.x && l.x < WIDTH && 0 < l.y && l.y < HEIGHT)
		e->picstr[l.y * WIDTH + l.x] = c.ca;
}
