/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:17:53 by hbruvry           #+#    #+#             */
/*   Updated: 2017/11/26 11:17:51 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*pdst;
	unsigned char	*psrc;
	unsigned char	pc;

	i = 0;
	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	pc = (unsigned char)c;
	while (i < n && (i == 0 || psrc[i - 1] != pc))
	{
		pdst[i] = psrc[i];
		i++;
	}
	if (i > 0 && psrc[i - 1] == pc)
		return (pdst + i);
	return (NULL);
}
