/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbnbr_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:23:02 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/14 16:29:24 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putbnbr_str(int i, uintmax_t n, char *nb, size_t base)
{
	char	*base_smbl;

	base_smbl = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOQRSTUVWXYZ";
	if (base > 62)
		base = 62;
	while (i >= 0 && nb[i] != '-')
	{
		nb[i] = base_smbl[n % base];
		n /= base;
		i--;
	}
}
