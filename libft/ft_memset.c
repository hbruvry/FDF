/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:05:32 by hbruvry           #+#    #+#             */
/*   Updated: 2017/12/02 11:11:27 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*pb;
	unsigned char	pc;

	i = 0;
	pb = (unsigned char*)b;
	pc = (unsigned char)c;
	while (i < len)
	{
		pb[i] = c;
		i++;
	}
	return (b);
}
