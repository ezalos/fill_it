/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_reach_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:31:49 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/04 20:31:57 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tab	*ft_tab_reach_end(t_tab *tab, size_t dir)
{
	t_tab		*tmp;

	if (!tab)
		return (NULL);
	tmp = tab;
	while (tmp->dir[dir])
		tmp = tmp->dir[dir];
	return (tmp);
}
