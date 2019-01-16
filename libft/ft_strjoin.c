/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:44:53 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/16 20:10:55 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size1;
	int		size2;
	int		i;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!(str = ft_strnew(size1 + size2)))
		return (NULL);
	i = -1;
	while (++i < size1)
		str[i] = s1[i];
	i = -1;
	while (++i < size2)
		str[i + size1] = s2[i];
	str[size1 + size2] = '\0';
	return (str);
}
