/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 08:59:02 by hbruvry           #+#    #+#             */
/*   Updated: 2018/02/20 12:16:13 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_inbase(char c, int base)
{
	if (base <= 10)
		return ('0' <= c && c <= '9');
	return (('0' <= c && c <= '9') || ('A' <= c && c <= ('A' + base - 10)));
}

int			ft_atoi_base(const char *str, int base)
{
	int	i;
	int	sign;
	int	atoi;

	i = 0;
	sign = 1;
	atoi = 0;
	if (base < 2 || base > 36)
		return (0);
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_inbase(str[i], base))
	{
		if (str[i] - 'A' >= 0)
			atoi = atoi * base + (str[i] - 'A' + 10);
		else
			atoi = atoi * base + (str[i] - '0');
		i++;
	}
	return (atoi * sign);
}
