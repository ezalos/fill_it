/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:06:53 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/10 14:52:22 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*exact;

	if ((size < 1) || !(exact = malloc(size)))
		return (NULL);
	while (size > 0)
		exact[size--] = 0;
	exact[0] = 0;
	return (exact);
}
