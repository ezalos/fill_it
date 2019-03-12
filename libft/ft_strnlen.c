/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:47:45 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/07 22:15:14 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

size_t		ft_strnlen(const char *s, size_t size)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && i < size)
		i++;
	return (i);
}
