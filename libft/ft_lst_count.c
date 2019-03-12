/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:12:56 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/22 19:12:57 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lst_count(t_list *lst, size_t i)
{
	t_list	*tmp;

	if (!lst->next)
		return (1);
	tmp = lst->next;
	i = 2;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
