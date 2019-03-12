/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:12:32 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/08 20:38:41 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*exact;

	if (!(exact = (char*)P_MALLOC(sizeof(char) * (++size))))
		return (NULL);
	while (size > 0)
		exact[--size] = '\0';
	exact[0] = '\0';
	return (exact);
}
