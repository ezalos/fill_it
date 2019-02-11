/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:11:44 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/11 10:48:18 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_n(size_t size, const char *str)
{
	size_t	i;

	i = 0;
	while (i <= size)
		if (str[i++] == '\0')
			return (i - 1);
	return (size);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dst;
	size_t	size_src;

	size_dst = ft_strlen_n(size, (const char*)dst);
	size_src = ft_strlen((const char*)src);
	if (size - size_dst > 1)
	{
		ft_strncpy(dst + size_dst, src, size - size_dst);
		dst[size - 1] = '\0';
	}
	return (size_src + size_dst);
}
