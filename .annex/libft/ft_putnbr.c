/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:48:33 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/09 14:18:45 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recur(int n)
{
	if (n != 0)
	{
		recur(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

void		ft_putnbr(int n)
{
	int		neg;

	neg = 1;
	if (n >= 0)
		neg = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (neg == 1)
	{
		if (n == -2147483648)
		{
			ft_putstr("-2147483648");
			return ;
		}
		ft_putchar('-');
		n = -n;
	}
	recur(n);
}
