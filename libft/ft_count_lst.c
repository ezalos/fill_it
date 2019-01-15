/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:44:37 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/04 14:55:56 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_lst(t_list *lst, size_t i)
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
