/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_multi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:14:54 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/08 20:37:36 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_multi(size_t nb, ...)
{
	va_list 	ap;
	size_t		size_total;
	int			i;
	int			j;
	int			k;
	char		**srcs;
	char		*dest;

	if (nb < 2)
		return (NULL);
	if (!(srcs = (char**)P_MALLOC(sizeof(char*) * nb)))
		return (NULL);
	va_start(ap, nb);
	i = -1;
	size_total = 0;
	while (++i < (int)nb)
	{
		srcs[i] = va_arg(ap, char*);
		if (!srcs[i])
		{
			if (1)
			{
				i--;
				nb--;
			}
			else
			{
				while (--i)
					ft_memdel((void**)&srcs[i]);
				ft_memdel((void**)&srcs);
				return (NULL);
			}
		}
		else
			size_total += ft_strlen(srcs[i]);
	}
	va_end(ap);
	if (!(dest = ft_strnew(size_total)))
	{
		while (--nb)
			ft_memdel((void**)&srcs[nb]);
		ft_memdel((void**)&srcs);
		return (NULL);
	}
	k = -1;
	i = -1;
	while (++i < (int)nb)
	{
		j = -1;
		while (srcs[i][++j])
			dest[++k] = srcs[i][j];
		ft_memdel((void**)&srcs[i]);
	}
	dest[size_total] = 0;
	ft_memdel((void**)&srcs);
	return (dest);
}
