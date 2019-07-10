/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:52:43 by hbruvry           #+#    #+#             */
/*   Updated: 2018/02/27 16:23:04 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	ft_putmap(void)
{
	t_inc	i;
	t_env	*e;

	i.i = 0;
	i.j = 0;
	e = ft_getenv();
	while (i.i < e->y)
	{
		ft_putstr("map[");
		ft_putnbr(i.i);
		ft_putstr("] = {");
		while (i.j < e->x)
		{
			if (i.j > 0)
				ft_putstr(", ");
			ft_putnbr(e->map[i.i][i.j]);
			i.j++;
		}
		ft_putstr("}\n");
		i.j = 0;
		i.i++;
	}
	return ;
}

void	ft_debug(void)
{
	t_env	*e;

	e = ft_getenv();
	ft_putstr("e->mlx = ");
	ft_putnbr((int)e->mlx);
	ft_putstr("\ne->win = ");
	ft_putnbr((int)e->win);
	ft_putstr("\n\n");
	ft_putmap();
	ft_putchar('\n');
	return ;
}
