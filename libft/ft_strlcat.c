/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:11:52 by hbruvry           #+#    #+#             */
/*   Updated: 2017/11/26 11:01:04 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		ret;

	i = 0;
	j = ft_strlen(dst);
	ret = ft_strlen(src) + j;
	while (src[i] != '\0' && j < size - 1 && size > 0)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	while (j < size)
	{
		dst[j] = '\0';
		j++;
	}
	if (ft_strlen(dst) > size)
		return (size + ft_strlen(src));
	return (ret);
}
