/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:40:27 by hbruvry           #+#    #+#             */
/*   Updated: 2018/01/31 07:40:59 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Join the buffer to the end of the string STR
*/

int		ft_bufjoin(const int fd, char **str, char *buf)
{
	int		ret;
	char	*fr;

	if ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		fr = *str;
		*str = ft_strjoin(*str, buf);
		free(fr);
		return (1);
	}
	return (0);
}

/*
** Split line according to '\n' character
*/

int		ft_linesplit(char **dst, char **src)
{
	int		i;
	char	*fr;

	i = 0;
	while ((*src)[i])
	{
		if ((*src)[i] == '\n')
		{
			fr = *src;
			*dst = ft_strsub(*src, 0, i);
			*src = ft_strsub(*src, i + 1, ft_strlen(*src));
			free(fr);
			return (1);
		}
		i++;
	}
	return (0);
}

/*
** Return a new string containing the next line of the file descriptor
*/

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static char		*str[OPEN_MAX];

	if (read(fd, buf, 0) == -1 || line == NULL
		|| BUFF_SIZE < 1 || fd > OPEN_MAX)
		return (-1);
	while (ft_bufjoin(fd, &str[fd], buf) > 0)
	{
		if (ft_linesplit(line, &str[fd]))
			return (1);
	}
	if (str[fd][0] == '\0')
		return (0);
	if (!ft_linesplit(line, &str[fd]))
	{
		*line = ft_strdup(str[fd]);
		ft_bzero(str[fd], ft_strlen(str[fd]));
	}
	return (1);
}
