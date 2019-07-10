/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:38:00 by hbruvry           #+#    #+#             */
/*   Updated: 2017/11/26 15:01:05 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
** Check if c is a character, entering the ASCII character set
*/

int	ft_isascii(int c)
{
	if (c < 0 || 127 < c)
		return (0);
	return (1);
}
