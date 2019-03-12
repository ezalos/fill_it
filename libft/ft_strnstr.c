/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:11:08 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/18 17:18:18 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;

	if (!*needle)
		return ((char*)haystack);
	while (len > 0 && *haystack)
	{
		j = 0;
		while (haystack[j] == needle[j] && haystack[j] && needle[j] && j < len)
			j++;
		if (!needle[j])
			return ((char*)haystack);
		len--;
		haystack++;
	}
	return (NULL);
}
