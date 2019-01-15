/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:11:36 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/20 19:40:12 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	size;
	size_t	i;

	i = -1;
	size = ft_strlen(dest);
	while (++i < n && src[i] != '\0')
		dest[size + i] = src[i];
	dest[size + i] = '\0';
	return (dest);
}
