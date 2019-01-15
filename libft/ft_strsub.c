/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:54:23 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/11 14:07:18 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	size;
	char			*str;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (size + len < start)
		return (NULL);
	if (!(str = (char*)ft_strnew((int)len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		if (s[i] == '\0')
			i = len;
		i++;
	}
	return (str);
}
