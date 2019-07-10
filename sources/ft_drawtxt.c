/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 11:37:44 by hbruvry           #+#    #+#             */
/*   Updated: 2018/03/02 08:11:05 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	ft_drawnbr(char *str, int x, int y)
{
	int		c;
	t_env	*e;

	c = 0xFFFFFF;
	e = ft_getenv();
	mlx_string_put(e->mlx, e->win, x, y, c, str);
	free(str);
}

void	ft_drawtxt(void)
{
	int		w;
	int		h;
	int		c;
	t_env	*e;

	w = WIDTH;
	h = HEIGHT;
	c = 0xFFFFFF;
	e = ft_getenv();
	mlx_string_put(e->mlx, e->win, 25, 25, c, "FdF - hbruvry");
	mlx_string_put(e->mlx, e->win, w - 140, h - 101, c, "posx =");
	ft_drawnbr(ft_itoa(w / 2 + e->mx), w - 70, h - 101);
	mlx_string_put(e->mlx, e->win, w - 140, h - 84, c, "posy =");
	ft_drawnbr(ft_itoa(h / 2 + e->my), w - 70, h - 84);
	mlx_string_put(e->mlx, e->win, w - 140, h - 67, c, "scale =");
	ft_drawnbr(ft_itoa(e->s), w - 60, h - 67);
	mlx_string_put(e->mlx, e->win, w - 140, h - 50, c, "depth =");
	ft_drawnbr(ft_itoa(e->d), w - 60, h - 50);
	return ;
}
