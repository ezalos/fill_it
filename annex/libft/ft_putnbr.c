/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:48:33 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/14 15:11:12 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

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
		return (ft_putchar('0'));
	if (neg == 1)
	{
		if (n == -2147483648)
			return (ft_putstr("-2147483648"));
		ft_putchar('-');
		n = -n;
	}
	recur(n);
}
