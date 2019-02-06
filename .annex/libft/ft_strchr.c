/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:12:04 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/20 19:46:08 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (c == 0)
		return ((char*)s + ft_strlen(s));
	while (*(char*)s != (char)c)
		if (*(s++) == 0)
			return (NULL);
	return ((char*)s);
}
