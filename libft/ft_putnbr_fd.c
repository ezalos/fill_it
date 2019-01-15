/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:29:00 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/09 14:14:20 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recur(int n, int fd)
{
	if (n != 0)
	{
		recur(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	int		neg;

	neg = 1;
	if (n >= 0)
		neg = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (neg == 1)
	{
		if (n == -2147483648)
		{
			ft_putstr_fd("-2147483648", fd);
			return ;
		}
		ft_putchar_fd('-', fd);
		n = -n;
	}
	recur(n, fd);
}
