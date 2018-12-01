/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:00:17 by aboitier          #+#    #+#             */
/*   Updated: 2018/11/19 12:58:27 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	i;

	if (!(dup = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (0);
	i = 0;
	while (*s1)
		dup[i++] = *s1++;
	dup[i] = '\0';
	return (dup);
}
