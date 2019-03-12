/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:25:10 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/14 16:25:58 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_nb_to_a(intmax_t n, size_t base)
{
	char	*nb_str;
	size_t	size;
	int		neg;
	uintmax_t nb;

	neg = 1;
	if (n >= 0)
		neg = 0;
	if (base == 0)
		base = 10;
	size = ft_nb_len(n, base);
	if (!(nb_str = ft_strnew(size)))
		return (NULL);
	if (neg == 1)
	{
		nb_str[0] = '-';
		nb = -n;
	}
	else
		nb = n;
	ft_putbnbr_str(size - 1, nb, nb_str, base);
	return (nb_str);
}
