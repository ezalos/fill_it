/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 20:59:43 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/12 21:06:44 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *one, void *two, size_t size)
{
	char	tmp;
	size_t	i;

	i = -1;
	while (++i < size)
	{
		tmp = *(char*)(one + i);
		*(char*)(one + i) = *(char*)(two + i);
		*(char*)(two + i) = tmp;
	}
}
