/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:11:03 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/21 13:24:51 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		walker;

	walker = ft_strlen(s) + 1;
	if (c == 0)
		return ((char*)s + walker - 1);
	while (s[--walker] != (const char)c)
		if (walker == 0)
			return (NULL);
	return ((char*)s + walker);
}
