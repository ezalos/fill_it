/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:38:45 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/11 14:06:19 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	size;
	char			*str;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (size < 1 || !(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[size] = 0;
	return (str);
}
