/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pstrnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:30:50 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/11 14:32:05 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_pstrnstr(const char *m, const char *a, size_t len)
{
	int		walker;
	size_t	ascent;

	ascent = 0;
	if (*a == '\0')
		return ((char*)m);
	if (len < ft_strlen(a))
		return (NULL);
	walker = 0;
	while (ascent + walker < len && m[ascent + walker] != '\0')
	{
		walker = 0;
		while (a[walker] == m[ascent + walker] && ascent + walker <= len)
			if (a[++walker] == '\0')
				return ((char*)m + ascent);
		ascent++;
	}
	return (NULL);
}
