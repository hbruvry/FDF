/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mousehook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 08:51:23 by hbruvry           #+#    #+#             */
/*   Updated: 2018/02/28 12:07:56 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

/*
** Focus map using mouse click
*/

int		ft_mousehook(int key, int x, int y, t_env *e)
{
	static int	i = 0;
	static int	s = 0;

	key = 0;
	if (i == 1)
	{
		e->mx = 0;
		e->my = 0;
		e->s = s;
		i = 0;
	}
	else
	{
		e->mx = e->mx - (x - WIDTH / 2) * 5;
		e->my = e->my - (y - HEIGHT / 2) * 5;
		s = e->s;
		e->s = s * 5;
		i = 1;
	}
	mlx_destroy_image(e->mlx, e->pic);
	e->pic = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	ft_drawmap();
	ft_drawtxt();
	return (0);
}
