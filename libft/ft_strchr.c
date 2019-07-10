/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:48:10 by hbruvry           #+#    #+#             */
/*   Updated: 2017/11/25 17:16:41 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
** Return a pointer to the first occurrence of the character c in the string s
*/

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*ps;
	char	pc;

	i = 0;
	ps = (char*)s;
	pc = (char)c;
	while (ps[i] != '\0')
	{
		if (ps[i] == pc)
			return (ps + i);
		i++;
	}
	if (ps[i] == pc)
		return (ps + i);
	return (NULL);
}
