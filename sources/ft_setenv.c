/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 13:16:29 by hbruvry           #+#    #+#             */
/*   Updated: 2018/03/06 12:28:02 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		ft_filelen(char *file)
{
	int		i;
	int		fd;
	char	buf[4096 + 1];
	char	*line;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	if (!read(fd, buf, 4096) || close(fd) == -1)
		return (0);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &line) == 1 && i < 10000)
	{
		free(line);
		i++;
	}
	if (close(fd) == -1)
		return (0);
	return (i);
}

char	***ft_filecpy(char *file, t_env *e)
{
	char	*line;
	char	***tmp;
	t_inc	i;

	i.j = 0;
	if (!(i.i = ft_filelen(file))
		|| (i.l = open(file, O_RDONLY)) == -1
		|| !(tmp = ft_memalloc(i.i * sizeof(char**))))
		return (NULL);
	i.i = 0;
	while (get_next_line(i.l, &line) == 1)
	{
		tmp[i.i] = ft_strsplit(line, ' ');
		free(line);
		while (tmp[i.i][i.j])
			i.j++;
		if (i.i != 0 && i.k != i.j)
			return (NULL);
		i.i++;
		i.k = i.j;
	}
	e->x = i.j;
	e->y = i.i;
	return (tmp);
}

/*
** Define env structure
*/

int		ft_setenv(char *file, t_env *e)
{
	char	***tmp;
	t_inc	i;

	i.i = -1;
	i.j = -1;
	if (!(tmp = ft_filecpy(file, e))
		|| !(e->map = ft_memalloc(e->y * sizeof(int*))))
		return (0);
	while (++i.i < e->y)
	{
		if (!(e->map[i.i] = ft_memalloc(e->x * sizeof(int))))
			return (0);
		while (++i.j < e->x)
		{
			e->map[i.i][i.j] = ft_atoi(tmp[i.i][i.j]);
			free(tmp[i.i][i.j]);
			e->zmax = (e->map[i.i][i.j] > e->zmax) ? e->map[i.i][i.j] : e->zmax;
			e->zmin = (e->map[i.i][i.j] < e->zmin) ? e->map[i.i][i.j] : e->zmin;
		}
		free(tmp[i.i]);
		i.j = -1;
	}
	free(tmp);
	e->mw = ((float)WIDTH - 50) / (((e->x + e->y) / 2 - 1) * 40);
	return (1);
}
