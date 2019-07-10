/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:20:34 by hbruvry           #+#    #+#             */
/*   Updated: 2017/12/02 20:20:42 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int res;

	res = 0;
	if (n == -2147483648)
	{
		ft_putnbr_fd(-2, fd);
		ft_putnbr_fd(147483648, fd);
		return ;
	}
	if (n < 0)
	{
		n = n * -1;
		ft_putchar_fd('-', fd);
	}
	if (n >= 0)
	{
		res = (n % 10) + '0';
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(res, fd);
	}
	return ;
}
