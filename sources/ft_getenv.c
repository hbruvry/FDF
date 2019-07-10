/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 13:49:05 by hbruvry           #+#    #+#             */
/*   Updated: 2018/06/12 13:22:25 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_env	*ft_getenv(void)
{
	static	t_env *e = NULL;

	if (e)
		return (e);
	if (!(e = ft_memalloc(sizeof(t_env))))
		return (NULL);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Fdf");
	e->pic = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->picstr = (int*)mlx_get_data_addr(e->pic, &e->a, &e->b, &e->c);
	e->map = NULL;
	e->x = 0;
	e->y = 0;
	e->zmax = 0;
	e->mx = 0;
	e->my = 0;
	e->mw = 0;
	e->ca = 0xFF0000;
	e->cb = 0x808000;
	e->cc = 0x00FF00;
	e->s = 100;
	e->d = 100;
	e->r = 0;
	e->td = 100;
	return (e);
}
