/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:03:01 by hbruvry           #+#    #+#             */
/*   Updated: 2017/11/26 15:07:55 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
** Put alphabetic character to upper case
*/

int	ft_toupper(int c)
{
	if (ft_isalpha(c))
		if (c >= 'a')
			return (c - 'a' + 'A');
	return (c);
}
