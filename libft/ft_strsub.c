/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:38:07 by hbruvry           #+#    #+#             */
/*   Updated: 2017/12/02 20:17:04 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
** Create new string copy of a section of the string passed as a parameter,
** the stretch starts at the index start and has for length len
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*ps;

	i = 0;
	ps = NULL;
	if (s != NULL)
	{
		ps = ft_strnew(len);
		if (ps == NULL)
			return (NULL);
		while (len > 0)
		{
			ps[i] = s[start + i];
			i++;
			len--;
		}
	}
	return (ps);
}
