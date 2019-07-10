/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:16:29 by hbruvry           #+#    #+#             */
/*   Updated: 2017/12/02 19:17:22 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1) + 1;
	s2 = (char*)malloc(len * sizeof(*s2));
	if (s2 == NULL)
		return (0);
	ft_memcpy(s2, s1, len);
	return (s2);
}
