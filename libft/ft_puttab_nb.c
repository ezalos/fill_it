/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:03:37 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/09 13:47:05 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab_nb(int length, int separation)
{
	int		n;
	int		tab;
	char	space;

	n = 4;
	tab = 0;
	space = ' ';
	while (tab + length < separation * n)
	{
		write(1, &space, 1);
		tab++;
	}
}
