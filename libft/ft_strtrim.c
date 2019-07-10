/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 18:38:08 by hbruvry           #+#    #+#             */
/*   Updated: 2017/11/26 19:21:59 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
** Create a new string copy of the string passed in parameter
** without the whitespace at the beginning and the end of this chain
*/

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	size_t			len;
	char			*strim;

	i = 0;
	len = 0;
	strim = NULL;
	if (s != NULL)
	{
		while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
			i++;
		len = ft_strlen(s) - 1;
		while ((s[len] == '\t' || s[len] == '\n' || s[len] == ' ') && len > i)
			len--;
		strim = ft_strnew(len - i + 1);
		if (strim == NULL)
			return (NULL);
		strim = ft_strsub(s, i, len - (size_t)i + 1);
	}
	return (strim);
}
