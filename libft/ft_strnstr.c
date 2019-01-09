/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:11:08 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/11 13:46:02 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *meul, const char *aig, size_t len)
{
	int		walker;
	size_t	ascent;

	ascent = 0;
	if (*aig == '\0')
		return ((char*)meul);
	if (len < ft_strlen(aig))
		return (NULL);
	walker = 0;
	while (ascent + walker < len && meul[ascent + walker] != '\0')
	{
		walker = 0;
		while (aig[walker] == meul[ascent + walker] && ascent + walker <= len)
			if (aig[++walker] == '\0')
				return ((char*)meul + ascent);
		ascent++;
	}
	return (NULL);
}
