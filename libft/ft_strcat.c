/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:12:11 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/13 17:43:15 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	size;
	int	i;

	i = -1;
	size = ft_strlen(dest);
	while (src[++i])
		dest[size + i] = src[i];
	dest[size + i] = '\0';
	return (dest);
}
