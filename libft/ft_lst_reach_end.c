/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_reach_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:53:21 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/16 13:58:57 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lst_reach_end(t_list *alst)
{
	t_list		*tmp;

	if (alst != NULL)
	{
		tmp = alst;
		while (tmp->next)
			tmp = tmp->next;
		return (tmp);
	}
	return (NULL);
}
