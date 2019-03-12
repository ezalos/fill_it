/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_dirth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:05:25 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/04 17:19:35 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tab		*ft_tab_dirth(t_tab *tab, size_t dir, size_t umpteenth)
{
	t_tab	*tmp;
	size_t	i;

	if (!tab || dir > 3)
		return (0);
	tmp = tab;
	i = 1;
	while (tmp->dir[dir] && i <= umpteenth)
	{
		tmp = tmp->dir[dir];
		i++;
	}
	return (tmp);
}
