/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:10:54 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/20 19:35:13 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *meule_de_foin, const char *aiguille)
{
	int		walker;

	if (*aiguille == '\0')
		return ((char*)meule_de_foin);
	if (ft_strlen(meule_de_foin) < ft_strlen(aiguille))
		return (NULL);
	walker = 0;
	while (meule_de_foin[walker] != '\0')
	{
		while (aiguille[walker] == meule_de_foin[walker])
			if (aiguille[++walker] == '\0')
				return ((char*)meule_de_foin);
		meule_de_foin++;
		walker = 0;
	}
	return (NULL);
}
