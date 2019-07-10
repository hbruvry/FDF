/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:13:42 by hbruvry           #+#    #+#             */
/*   Updated: 2017/11/26 17:25:18 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
** Applies the function f to each character in the string passed
** in parameter by specifying its index for create a new string
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ps;

	i = 0;
	ps = NULL;
	if (s != NULL && f != NULL)
	{
		ps = ft_strdup(s);
		if (ps == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			ps[i] = f(i, s[i]);
			i++;
		}
	}
	return (ps);
}
