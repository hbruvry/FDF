/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 12:30:44 by hbruvry           #+#    #+#             */
/*   Updated: 2018/02/20 13:12:53 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdio.h>

char	*ft_getres(int i, int neg, int *itoa)
{
	char	*base;
	char	*str;
	int		j;

	j = neg;
	base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (!(str = (char *)malloc(i * sizeof(char))))
		return (NULL);
	i--;
	if (neg == 1)
		str[0] = '-';
	while (i >= 0)
	{
		str[j] = base[itoa[i]];
		j++;
		i--;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_itoa_base(int n, int base)
{
	int			i;
	int			neg;
	long int	res;
	int			itoa[64];

	i = 0;
	neg = 0;
	res = n;
	if (n < 0)
	{
		res = res * -1;
		if (base == 10)
			neg = 1;
	}
	if (res == 0)
		return ("0");
	while (res != 0)
	{
		itoa[i] = res % base;
		res = res / base;
		i++;
	}
	return (ft_getres(i, neg, itoa));
}
