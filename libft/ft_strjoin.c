/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:53:04 by hbruvry           #+#    #+#             */
/*   Updated: 2018/01/11 08:44:19 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sjoin;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup((char*)s2));
	else if (s2 == NULL)
		return (ft_strdup((char*)s1));
	sjoin = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (sjoin == NULL)
		return (NULL);
	ft_strcpy(sjoin, s1);
	ft_strcat(sjoin, s2);
	return (sjoin);
}
