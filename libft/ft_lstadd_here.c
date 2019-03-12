/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_here.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:56:12 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/16 14:02:14 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_here(t_list *alst, t_list *new)
{
	t_list		*tmp;

	if (alst != NULL)
	{
		tmp = alst->next;
		alst->next = new;
		ft_lst_reach_end(new)->next = tmp;
	}
}
