/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:03:58 by hbruvry           #+#    #+#             */
/*   Updated: 2017/11/26 11:51:34 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	if (psrc < pdst)
	{
		while (len > 0)
		{
			pdst[len - 1] = psrc[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
