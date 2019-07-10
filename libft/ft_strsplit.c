/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 04:16:23 by alsomvil          #+#    #+#             */
/*   Updated: 2018/02/20 13:17:09 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*lenword(char const *s, char c)
{
	int		i;
	char	*temp;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(temp = ft_memalloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

static int	nbword(char const *s, char c)
{
	int		word;
	int		i;

	word = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		word++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	if (!(tab = malloc(sizeof(char *) * (nbword(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
			tab[j++] = lenword(&s[i], c);
		while (s[i] && s[i] != c)
			i++;
	}
	tab[j] = 0;
	return (tab);
}
