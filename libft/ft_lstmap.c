/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:24:18 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/16 20:08:02 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr_old;
	t_list	*head;
	t_list	*ptr;

	if (lst != NULL && f != NULL)
	{
		ptr_old = lst;
		if (!(head = f(ptr_old)))
			return (NULL);
		ptr = head;
		ptr_old = ptr_old->next;
		while (ptr_old->next != NULL)
		{
			if (!(ptr->next = f(ptr_old)))
				return (NULL);
			ptr = ptr->next;
			ptr_old = ptr_old->next;
		}
		if (!(ptr->next = f(ptr_old)))
			return (NULL);
		ptr->next->next = NULL;
		return (head);
	}
	return (NULL);
}
