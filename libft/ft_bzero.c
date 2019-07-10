/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:54:13 by hbruvry           #+#    #+#             */
/*   Updated: 2017/11/23 18:11:34 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/*
** Sets to 0 the first n bytes of the block pointed to by s
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
	return ;
}
