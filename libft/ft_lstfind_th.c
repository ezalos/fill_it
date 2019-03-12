/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_th.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:37:06 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/22 19:14:40 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind_th(t_list *lst, size_t umpteenth)
{
	t_list	*tmp;
	size_t	i;

	tmp = lst;
	i = 0;
	while (i < umpteenth)
	{
		if (!tmp)
			return (tmp);
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}
