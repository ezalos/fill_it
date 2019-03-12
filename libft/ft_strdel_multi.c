/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_multi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:14:54 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/22 19:10:24 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel_multi(size_t nb, ...)
{
	va_list 	ap;
	int			i;
	char		**as;

	if (nb != 0)
	{
		va_start(ap, nb);
		i = -1;
		while (++i < (int)nb)
		{
			as = va_arg(ap, char**);
			if (as != NULL)
				if (*as != NULL)
				{
					free(as);
					as = NULL;
				}
		}
		va_end(ap);
	}
}
