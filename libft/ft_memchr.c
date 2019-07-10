/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:37:14 by hbruvry           #+#    #+#             */
/*   Updated: 2017/11/25 15:51:27 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ps;
	unsigned char	pc;

	i = 0;
	ps = (unsigned char*)s;
	pc = (unsigned char)c;
	while (i < n)
	{
		if (ps[i] == pc)
			return (ps + i);
		i++;
	}
	return (NULL);
}
