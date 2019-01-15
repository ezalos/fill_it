/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:12:31 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/11 17:35:42 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	i = 0;
	if ((char*)dest > (char*)src)
		while (n-- > i)
			((char*)dest)[n] = ((char*)src)[n];
	else
		while (i++ < n)
			((char*)dest)[i - 1] = ((char*)src)[i - 1];
	return (dest);
}
