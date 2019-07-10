/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:13:42 by hbruvry           #+#    #+#             */
/*   Updated: 2017/11/26 17:23:07 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		ls;
	char	*ps;

	i = 0;
	ls = 0;
	ps = NULL;
	if (s != NULL && f != NULL)
	{
		ps = ft_strdup(s);
		if (ps == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			ps[i] = f(s[i]);
			i++;
		}
	}
	return (ps);
}
