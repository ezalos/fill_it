/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:28:56 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/08 20:38:08 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		size;
	char	*str;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (size < 1 || !(str = (char*)P_MALLOC(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = 0;
	while (--size >= 0)
		str[size] = f(s[size]);
	return (str);
}
