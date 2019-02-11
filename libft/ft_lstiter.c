/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:23:39 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/11 14:38:41 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*ptr;

	if (lst != NULL && f != NULL)
	{
		ptr = lst;
		while (ptr->next != NULL)
		{
			f(ptr);
			ptr = ptr->next;
		}
		f(ptr);
	}
}
