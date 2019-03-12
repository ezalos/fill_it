/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:03:37 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/15 16:09:36 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_puttab_len(size_t length, size_t separation, size_t n)
{
	size_t		tab;

	if (n == 0)
		n = 1;
	tab = 0;
	while (tab + length < separation * n)
	{
		write(1, " ", n);
		tab += n;
	}
	return (tab);
}
