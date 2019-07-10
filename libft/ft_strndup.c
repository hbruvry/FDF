/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 16:54:57 by hbruvry           #+#    #+#             */
/*   Updated: 2018/07/18 16:54:59 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
** Returns a pointer to a new string that is duplicated since s,
** copy no more than n characters
*/

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1);
	if (n > len)
		n = len;
	s2 = (char*)malloc((n + 1) * sizeof(*s2));
	if (s2 == NULL)
		return (0);
	ft_memcpy(s2, s1, n);
	return (s2);
}
