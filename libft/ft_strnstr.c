/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:40:08 by hbruvry           #+#    #+#             */
/*   Updated: 2017/11/25 18:20:15 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	llittle;
	char	*pbig;

	i = 0;
	j = 0;
	llittle = ft_strlen(little);
	pbig = (char*)big;
	if (llittle == 0)
		return (pbig);
	while (pbig[i] != '\0')
	{
		while (pbig[i + j] == little[j] && i + j < len)
		{
			if (j == llittle - 1)
				return (pbig + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
