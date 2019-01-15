/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:49:47 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/11 20:36:12 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (s1 == NULL && s2 == NULL)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (n == 0)
		return (1);
	i = 0;
	while (s1[i] == s2[i] && i < n)
	{
		if (s1[i] == s2[i] && s1[i] == '\0')
			return (1);
		i++;
	}
	if (i == n && s1[i - 1] == s2[i - 1])
		return (1);
	return (0);
}
