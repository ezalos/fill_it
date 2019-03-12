/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:09:32 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/25 22:09:40 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tab		*ft_tabnew_dir(size_t len, size_t dir)
{
	t_tab	*head;
	t_tab	*segment;
	int		i;

	if (!len || dir > 3 || !(head = ft_tabnew_ptr(NULL, 0)))
		return (NULL);
	segment = head;
	i = 0;
	while (++i < (int)len)
	{
		if (!(segment->dir[dir] = ft_tabnew_ptr(NULL, 0)))
			return (NULL);
		segment->dir[dir]->dir[ft_tab_dir_reverse(dir)] = segment;
		segment = segment->dir[dir];
	}
	return (head);
}
