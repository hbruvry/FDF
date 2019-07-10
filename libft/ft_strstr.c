/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:54:00 by hbruvry           #+#    #+#             */
/*   Updated: 2017/11/25 17:14:28 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
** Look for the first occurrence of little substring in big string
*/

char	*ft_strstr(const char *big, const char *little)
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
		while (pbig[i + j] == little[j])
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
