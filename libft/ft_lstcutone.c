/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcutone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 01:53:37 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/10 20:06:10 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstcutone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;

	ptr = (*alst)->next->next;
	del((*alst)->next->content, (*alst)->next->content_size);
	free((*alst)->next);
	(*alst)->next = ptr;
}
