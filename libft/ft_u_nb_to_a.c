/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_nb_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:26:38 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/14 16:27:01 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_u_nb_to_a(uintmax_t n, size_t base)
{
	char	*nb_str;
	size_t	size;
	uintmax_t nb;

	size = ft_u_nb_len(n, base);
	if (!(nb_str = ft_strnew(size)))
		return (NULL);
	else
		nb = n;
	ft_putbnbr_str(size - 1, nb, nb_str, base);
	return (nb_str);
}
