/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:24:27 by hbruvry           #+#    #+#             */
/*   Updated: 2018/06/12 11:02:25 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

/*
** Control position, scale and depth
*/

void	ft_ctrlbasic(int key, t_env *e)
{
	int		i;

	i = 5;
	if (key == 0)
		e->mx -= i;
	if (key == 1)
		e->my += i;
	if (key == 2)
		e->mx += i;
	if (key == 13)
		e->my -= i;
	if (key == 123)
		e->d -= i;
	if (key == 123)
		e->td -= i;
	if (key == 124)
		e->d += i;
	if (key == 124)
		e->td += i;
	if (key == 125)
		e->s -= i;
	if (key == 126)
		e->s += i;
	return ;
}

/*
** Control map using key and redraw map
*/

int		ft_hook(int key, t_env *e)
{
	ft_ctrlbasic(key, e);
	mlx_destroy_image(e->mlx, e->pic);
	e->pic = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->picstr = (int*)mlx_get_data_addr(e->pic, &e->a, &e->b, &e->c);
	ft_drawmap();
	ft_drawtxt();
	return (0);
}

/*
** Depth oscillation
*/

int		ft_loophook(t_env *e)
{
	int i;

	i = 5;
	if (e->k == 1)
	{
		if (e->d == e->td)
			e->td = e->td * -1;
		if (e->d > e->td)
			e->d -= i;
		else
			e->d += i;
	}
	mlx_destroy_image(e->mlx, e->pic);
	e->pic = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->picstr = (int*)mlx_get_data_addr(e->pic, &e->a, &e->b, &e->c);
	ft_drawmap();
	ft_drawtxt();
	return (0);
}

/*
** Use ft_debug(); to see get informations about mlx and map structures
*/

void	ft_fdf(void)
{
	t_env	*e;

	e = ft_getenv();
	ft_putstr("place : w/a/s/d\nscale : up/down\ndepth : left/right\n");
	ft_putstr("rotat : +/-\ncolor : 0/1/2/3\nfocus : left click\n");
	ft_putstr("whouw : space\nreset : delete\nclose : escape");
	ft_drawmap();
	ft_drawtxt();
	mlx_hook(e->win, 2, 5, ft_hook, e);
	mlx_key_hook(e->win, ft_keyhook, e);
	mlx_loop_hook(e->mlx, ft_loophook, e);
	mlx_mouse_hook(e->win, ft_mousehook, e);
	mlx_loop(e->mlx);
	return ;
}

int		main(int argc, char **argv)
{
	t_env	*e;

	e = ft_getenv();
	if (argc != 2)
	{
		ft_putstr("usage: ./fdf source_file\n");
		return (0);
	}
	else
	{
		if (!ft_setenv(argv[1], e))
		{
			ft_putstr("error\n");
			return (0);
		}
		ft_fdf();
	}
	return (1);
}
