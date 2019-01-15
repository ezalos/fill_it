/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:03:31 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/09 03:15:35 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fill_it_files/head.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((char*)str)[i++] = (char)c;
	return (str);
}
