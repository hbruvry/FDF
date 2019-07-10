/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:54:16 by hbruvry           #+#    #+#             */
/*   Updated: 2018/03/02 08:35:09 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	ft_free(t_env *e)
{
	t_inc	i;

	i.i = -1;
	while (++i.i < e->y)
		free(e->map[i.i]);
	free(e->map);
	free(e);
}

void	ft_ctrlcolor(int key, t_env *e)
{
	if (key == 82)
	{
		e->ca = 0x000000;
		e->cb = 0x808080;
		e->cc = 0xFFFFFF;
	}
	if (key == 83)
	{
		e->ca = 0xFF0000;
		e->cb = 0x808000;
		e->cc = 0x00FF00;
	}
	if (key == 84)
	{
		e->ca = 0x00FF00;
		e->cb = 0x008080;
		e->cc = 0x0000FF;
	}
	if (key == 85)
	{
		e->ca = 0x0000FF;
		e->cb = 0x800080;
		e->cc = 0xFF0000;
	}
	return ;
}

/*
** Control rotation, animation, reset and exit
*/

void	ft_ctrlglobal(int key, t_env *e)
{
	if (key == 49)
		e->k = (e->k == 0) ? 1 : 0;
	if (key == 51)
	{
		e->s = 100;
		e->d = 100;
		e->r = 0;
		e->td = 100;
		e->mx = 0;
		e->my = 0;
	}
	if (key == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		ft_free(e);
		exit(0);
	}
	if (key == 69)
		e->r -= 0.2;
	if (key == 78)
		e->r += 0.2;
	return ;
}

/*
** Control map using key and redraw map
*/

int		ft_keyhook(int key, t_env *e)
{
	ft_ctrlcolor(key, e);
	ft_ctrlglobal(key, e);
	mlx_destroy_image(e->mlx, e->pic);
	e->pic = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->picstr = (int*)mlx_get_data_addr(e->pic, &e->a, &e->b, &e->c);
	ft_drawmap();
	ft_drawtxt();
	return (0);
}
