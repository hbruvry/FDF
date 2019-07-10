/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 12:51:28 by hbruvry           #+#    #+#             */
/*   Updated: 2017/11/26 12:56:07 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
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
	if (i < n)
		return (ps1[i] - ps2[i]);
	return (0);
}
