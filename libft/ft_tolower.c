/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:12:10 by hbruvry           #+#    #+#             */
/*   Updated: 2017/11/26 15:12:30 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
** Put alphabetic character to lower case
*/

int	ft_tolower(int c)
{
	if (ft_isalpha(c))
		if (c <= 'Z')
			return (c - 'A' + 'a');
	return (c);
}
