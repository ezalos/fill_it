/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboitier <aboitier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:45:13 by aboitier          #+#    #+#             */
/*   Updated: 2018/11/27 18:45:19 by aboitier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_list	*ft_lstfind(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list *list;

	list = begin_list;
	if (!begin_list)
		return (NULL);
	while (list)
	{
		if (cmp(list->content, data_ref) == 0)
			return (list);
		list = list->next;
	}
	return (0);
}
