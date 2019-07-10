/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:11:29 by hbruvry           #+#    #+#             */
/*   Updated: 2017/11/26 12:28:48 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ps;
	char	pc;

	i = (int)ft_strlen(s);
	ps = (char*)s;
	pc = (char)c;
	while (i >= 0)
	{
		if (ps[i] == pc)
			return (ps + i);
		i--;
	}
	return (NULL);
}
