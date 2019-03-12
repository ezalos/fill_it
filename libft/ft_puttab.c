/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:00:23 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/15 16:10:24 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_puttab(const char *s, size_t separation)
{
	if (!s)
		return (0);
	return (ft_puttab_len(ft_strlen(s), separation, 1));
}
