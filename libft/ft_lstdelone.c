/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:21:29 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/11 14:38:22 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst != NULL && *alst != NULL && del != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
