/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:22:03 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/11 14:38:25 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*tmp;

	if (alst != NULL && *alst != NULL && del != NULL)
	{
		ptr = *alst;
		while (ptr->next != NULL)
		{
			tmp = ptr;
			ptr = ptr->next;
			ft_lstdelone(&tmp, del);
		}
		ft_lstdelone(&ptr, del);
		*alst = NULL;
	}
}
