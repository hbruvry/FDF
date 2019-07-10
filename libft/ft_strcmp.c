/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 12:37:51 by hbruvry           #+#    #+#             */
/*   Updated: 2017/11/26 12:50:11 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	i = 0;
	ps1 = (unsigned char*)s1;
	ps2 = (unsigned char*)s2;
	while (ps1[i] != '\0' && ps2[i] != '\0' && ps1[i] == ps2[i])
	{
		i++;
	}
	return (ps1[i] - ps2[i]);
}
