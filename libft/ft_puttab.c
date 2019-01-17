/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:00:23 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/17 16:59:51 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab(const char *s, int separation)
{
	int n;
	int tab;
	int length;

	n = 4;
	tab = 0;
	length = ft_strlen(s);
	while (tab + length < separation * n)
	{
		write(1, " ", 1);
		tab++;
	}
}
