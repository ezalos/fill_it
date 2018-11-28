/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:40:30 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/27 02:24:17 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		size_square(int p)
{
	return (float_to_int(f_sqrt(p, 0) * 2));
}

int		size_pieces(char *s, int size)
{
	if (*s == 'O')
		return ((size - 1) * (size - 1));
	else if (*s == 'I')
		return ((size - 3) * size);
	else
		return ((size - 1) * (size - 2));
}
